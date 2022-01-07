%{
  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include <math.h>
  #include <ctype.h>
  #include "ST.h"
  #define YYDEBUG 1
  int yylex(void);
  void yyerror(char *);

  int curr_scope = 0;


  void install ( char *sym_name, int type, int int_val, double real_val, int bool_val, int current_scope)
  {
    symrec *s;
    symrec *i;
    s = getsym (sym_name, current_scope);
    if (s == 0) {
      putsym (sym_name, type, int_val, real_val, bool_val, current_scope);   
    } else { 
      printf( "%s is already defined\n", sym_name );
    }
  }

  void context_check( char *sym_name, int scope ) { 
    symrec *identifier;
    identifier = getsym( sym_name, scope );
    if ( identifier == 0 ) { 
      printf( "%s", sym_name );
      printf( "%s\n", " is an undeclared identifier" );
      exit(1);
    }
  }

  void check_type( char *sym_name, int type, int scope) { 
    symrec *identifier;
    identifier = getsym( sym_name , scope);
    if(identifier->type != type) {
      printf( "%s", sym_name );
      int int_type = identifier->type;
      printf( "%s\n", " hasn't the right type" );
      exit(1);
    }
    
  }

  void set_real_value(char *sym_name, double real_value, int current_scope) {
    setrealval(sym_name, real_value, current_scope);
  }

  double get_real_value(char *sym_name, int current_scope) {
    return getrealval(sym_name, current_scope);
  }

  void set_bool_value(char *sym_name, int bool_value, int current_scope) {
    setboolval(sym_name, bool_value, current_scope);
  }

  int get_bool_value(char *sym_name, int current_scope) {
    return getboolval(sym_name, current_scope);
  }

  void set_int_value(char *sym_name, int int_value, int current_scope) {
    setintval(sym_name, int_value, current_scope);
  }

  int get_int_value(char *sym_name, int current_scope) {
    return getintval(sym_name, current_scope);
  }



%}


%union semrec 
{
  double doubleval;
  int intval; 
  char *chstval;
  char *id;
  struct lbs *lbls; 
}

%token <id> ID;

%token TRUE FALSE REAL INTEGER CHAR STRING INT_TYPE REAL_TYPE CHAR_TYPE STRING_TYPE BOOL_TYPE;
%type <intval> type INT_TYPE REAL_TYPE CHAR_TYPE STRING_TYPE BOOL_TYPE;


%type <intval> INTEGER intexpr intfactor intterm assignintexpr;
%type <doubleval> REAL number reaexpr reafactor reaterm assignreaexpr;
%type <intval> TRUE FALSE boolean booexpr boofactor booterm assignbooexpr;
%type <chstval> CHAR STRING charsandstrings

%token VAR COLON OPENPAR CLOSEPAR COMMA COMMENT SEMICOLON 
%token STARTPRGM ENDPRGM BEGSTMT ENDSTMT
%token IF THEN ELIF ELSE ENDIF WHILE DO ENDWHILE 
%token WRITE FCT RETURN
%token OR AND

%left ADDOP MINOP MULOP DIVOP DIV MOD ASSIGNMENT LE GE LT GT EQ NE 
%right NOT FLOOR CEIL POW ABS EXP LOG LN COS SIN TAN SQRT


%%

program: STARTPRGM declarations fcts stmts ENDPRGM; 

groupstmts: BEGSTMT stmts ENDSTMT
;

declarations: 
|     declarations declaration SEMICOLON
;

stmts: comment stmt SEMICOLON
|   stmts comment stmt SEMICOLON
;

stmt:  assignexpr  
|   declaration     
|   IF booexpr THEN groupstmts elifstmt elsestmt ENDIF    {printf("CONDITIONAL STATEMENT");}
|   WHILE booexpr DO groupstmts ENDWHILE       {printf("LOOP STATEMENT");}
|   write
|   callfct
;

declaration: VAR ID COLON type    { printf("curr_scope = %d\n", curr_scope); install($2, $4, 0, 0, 0, curr_scope); printf("DECLARATION %s, %d \n", $2, $4);}

comment: 
|   COMMENT
;

assignexpr: assignintexpr
|   assignreaexpr
|   assignbooexpr
;

assignintexpr: ID ASSIGNMENT INT_TYPE intexpr { context_check($1, curr_scope); check_type($1, INT_TYPE, curr_scope); set_int_value($1, $4, curr_scope); printf("INTEGER %d ASSIGNED TO %s\n", $4, $1);}
;

assignreaexpr: ID ASSIGNMENT REAL_TYPE reaexpr  { context_check($1, curr_scope); check_type($1, REAL_TYPE, curr_scope); set_real_value($1, $4, curr_scope); printf("REAL %f ASSIGNED TO %s\n", $4, $1);}
;

assignbooexpr: ID ASSIGNMENT BOOL_TYPE booexpr   { context_check($1, curr_scope); check_type($1, BOOL_TYPE, curr_scope); set_bool_value($1, $4, curr_scope); printf("BOOLEAN %d ASSIGNED TO %s\n", $4, $1);}
;

intexpr: intfactor              {$$ = $1; printf("MY INT FACTOR = %d\n", $$);}
|   intexpr ADDOP intfactor     { $$ = $1+$3; }
|   intexpr MINOP intfactor      { $$ = $1-$3; }
|   MINOP intfactor                { $$ = -$2; }
;

intfactor: intterm              {$$ = $1; printf("MY INT TERM = %d\n", $$);}
|   intfactor MULOP intterm    { $$ = $1*$3; }
|   intfactor DIVOP intterm    { $$ = $1/$3; }
|   intfactor DIV intterm      { $$ = floor($1 / $3); }
|   intfactor MOD intterm      { $$ = fmod($1, $3); }
;

intterm: INT_TYPE ID          { check_type($2, INT_TYPE, curr_scope); $$ = get_int_value($2, curr_scope); printf("MY INT = %d\n", $$); }
|       INTEGER             {$$ = $1;}
|    OPENPAR intexpr CLOSEPAR  {$$ = $2;}
|   ABS OPENPAR intexpr CLOSEPAR {$$ = abs($3);}
|   POW OPENPAR intexpr COMMA intexpr CLOSEPAR      {$$ = pow($3, $5);}
|   SQRT OPENPAR intexpr CLOSEPAR { if($3 >= 0) {$$ = sqrt($3); printf("result = %d\n", $$);} else{yyerror("Cannot make sqrt on negative number");exit(1);}}
|   EXP OPENPAR intexpr CLOSEPAR {$$ = exp($3); printf("result = %d\n", $$);}
|   LOG OPENPAR intexpr CLOSEPAR {if($3 >= 0) {$$ = log10($3); printf("result = %d\n", $$);} else {yyerror("Cannot make log on negative number");exit(1);}}
|   LN OPENPAR intexpr CLOSEPAR  {if($3 >= 0) {$$ = log($3); printf("result = %d\n", $$);} else {yyerror("Cannot make ln on negative number");exit(1);}}
|   FLOOR OPENPAR intexpr CLOSEPAR {$$ = floor($3); printf("result = %d\n", $$);}
|   CEIL OPENPAR intexpr CLOSEPAR  {$$ = ceil($3); printf("result = %d\n", $$);}
|   COS OPENPAR intexpr CLOSEPAR  {$$ = cos($3); printf("result = %d\n", $$);}
|   SIN OPENPAR intexpr CLOSEPAR  {$$ = sin($3); printf("result = %d\n", $$);}
|   TAN OPENPAR intexpr CLOSEPAR  {$$ = tan($3); printf("result = %d\n", $$);}
;

reaexpr: reafactor        {$$ = $1; printf("MY REAL FACTOR = %f\n", $$);}
|   reaexpr ADDOP reafactor   {$$ = $1+$3;}
|   reaexpr MINOP reafactor   {$$ = $1-$3;}
|   MINOP reafactor           {$$ = -$2;}
;

reafactor: reaterm            {$$ = $1;}
|   reafactor MULOP reaterm    {$$ = $1*$3;}
|   reafactor DIVOP reaterm    {$$ = $1/$3;}
|   reafactor DIV reaterm      {$$ = floor($1/$3);}
|   reafactor MOD reaterm      {$$ = fmod($1, $3);}
;

reaterm: REAL_TYPE ID       { check_type($2, REAL_TYPE, curr_scope); $$ = get_real_value($2, curr_scope); printf("MY REAL = %f\n", $$); }
|       number              {$$ = $1;}
|    OPENPAR reaexpr CLOSEPAR  {$$ = $2;}
|   ABS OPENPAR reaexpr CLOSEPAR {$$ = abs($3);}
|   POW OPENPAR reaexpr COMMA reaexpr CLOSEPAR    {$$ = pow($3, $5);}
|   SQRT OPENPAR reaexpr CLOSEPAR { if($3 >= 0) {$$ = sqrt($3); printf("result = %f\n", $$);} else{yyerror("Cannot make sqrt on negative number");exit(1);}}
|   EXP OPENPAR reaexpr CLOSEPAR {$$ = exp($3); printf("result = %f\n", $$);}
|   LOG OPENPAR reaexpr CLOSEPAR {if($3 >= 0) {$$ = log10($3); printf("result = %f\n", $$);} else {yyerror("Cannot make log on negative number");exit(1);}}
|   LN OPENPAR reaexpr CLOSEPAR  {if($3 >= 0) {$$ = log($3); printf("result = %f\n", $$);} else {yyerror("Cannot make ln on negative number");exit(1);}}
|   FLOOR OPENPAR reaexpr CLOSEPAR {$$ = floor($3); printf("result = %f\n", $$);}
|   CEIL OPENPAR reaexpr CLOSEPAR  {$$ = ceil($3); printf("result = %f\n", $$);}
|   COS OPENPAR reaexpr CLOSEPAR  {$$ = cos($3); printf("result = %f\n", $$);}
|   SIN OPENPAR reaexpr CLOSEPAR  {$$ = sin($3); printf("result = %f\n", $$);}
|   TAN OPENPAR reaexpr CLOSEPAR  {$$ = tan($3); printf("result = %f\n", $$);} 
;


number: INTEGER   {$$ = (float)$1; printf("MY INTEGER IS IN REAL = %f", $$);}
|   REAL          {$$ = $1; printf("MY REAL = %f", $$);}
;

booexpr: boofactor             {$$ = $1; printf("MY BOOL EXPR = %d\n", $$);}  
|   reaexpr GE reafactor      { $$ = $1 >= $3; printf("result = %d\n", $$);};  
|   reaexpr LE reafactor      { $$ = $1 <= $3; printf("result = %d\n", $$);};
|   reaexpr GT reafactor     { $$ = $1 > $3; printf("result = %d\n", $$);};
|   reaexpr LT reafactor      { $$ = $1 < $3; printf("result = %d\n", $$);};
|   reaexpr EQ reafactor     { $$ = $1 == $3; printf("result = %d\n", $$);};
|   reaexpr NE reafactor   { $$ = $1 != $3; printf("result = %d\n", $$);};
|   booexpr AND boofactor   { $$ = $1 && $3; printf("result = %d\n", $$);};
|   booexpr OR boofactor    { $$ = $1 || $3; printf("result = %d\n", $$);};
|   NOT boofactor            { $$ = (!$2); printf("result = %d\n", $$);};
;

boofactor:  booterm                     {$$ = $1; printf("result = %d\n", $$);}
;

booterm: BOOL_TYPE ID          { check_type($2, BOOL_TYPE, curr_scope); $$ = get_bool_value($2, curr_scope); printf("MY BOOL = %d\n", $$); }
|     boolean                   {$$ = $1; printf("IT IS A BOOLEAN \n");}
|     OPENPAR booexpr CLOSEPAR    {$$ = $2; printf("result = %d\n", $$);}
;

boolean: TRUE               { $$ = 1; printf("BOOL VALUE = %d\n", $$);}
|       FALSE               { $$ = 0; printf("BOOL VALUE = %d\n", $$);}
;


type: INT_TYPE   {$$ = INT_TYPE;}
|   REAL_TYPE     {$$ = REAL_TYPE;}
|   CHAR_TYPE     {$$ = CHAR_TYPE;}
|   STRING_TYPE   {$$ = STRING_TYPE;}
|   BOOL_TYPE     {$$ = BOOL_TYPE;}
;

elifstmt: 
|   elifstmt ELIF booexpr THEN groupstmts
;

elsestmt:
|   ELSE groupstmts
;

write: WRITE charsandstrings   {printf("WRITE: %s\n", $2);}
;

charsandstrings: CHAR    { $$ = $1; printf("OUR CHAR IS %s\n", $$);}
|      STRING            { $$ = $1; printf("OUR STRING IS %s\n", $$);}
;

fcts:  SEMICOLON
|   fcts fct
;

fct:  headfct groupstmts returnfct 
;

headfct: FCT ID OPENPAR parameters CLOSEPAR COLON type  { curr_scope++; printf("curr_scope = %d\n", curr_scope); }
;

returnfct: RETURN ID   {curr_scope--;  printf("curr_scope = %d\n", curr_scope);}
;


parameters: ID       { context_check($1, curr_scope); }
|   ID COMMA parameters     { context_check($1, curr_scope);}
;

instances: ID
|   INTEGER
|   REAL
|   CHAR
|   STRING
|   boolean
;

parametersinstances: instances 
|    instances COMMA parametersinstances
; 

callfct: ID ASSIGNMENT ID OPENPAR parametersinstances CLOSEPAR        
;

%%
void yyerror(char *s) {
    fprintf(stderr, "%s\n", s);
}
int main( int argc, char *argv[] ){ 
    extern FILE *yyin;
    ++argv; argc = argc-1;
    yyin = fopen( argv[0], "r" );
    int errors = 0;
    yyparse ();
}