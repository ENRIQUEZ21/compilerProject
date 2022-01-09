%{
  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include <math.h>
  #include <ctype.h>
  #include "variables.h"
  #include "ST.h"
  #include "ast.h"
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

  int get_type(char *sym_name, int scope) {
    symrec *identifier;
    identifier = getsym(sym_name, scope);
    return identifier->type;
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
  struct Value val;
  double doubleval;
  int intval; 
  char *chstval;
  char *id;
  struct lbs *lbls; 
}



%token <id> ID;

%token TRUE FALSE REAL INTEGER CHAR STRING INT_TYPE REAL_TYPE CHAR_TYPE STRING_TYPE BOOL_TYPE;
%type <intval> type INT_TYPE REAL_TYPE CHAR_TYPE STRING_TYPE BOOL_TYPE;

%type <val> INTEGER REAL TRUE FALSE;

%type <val> expr factor term;





%token VAR COLON OPENPAR CLOSEPAR COMMA COMMENT SEMICOLON 
%token STARTPRGM ENDPRGM BEGSTMT ENDSTMT
%token IF THEN ELIF ELSE ENDIF WHILE DO ENDWHILE 
%token WRITE FCT RETURN
%token OR AND

%left ADDOP MINOP MULOP DIVOP DIV MOD ASSIGNMENT LE GE LT GT EQ NE 
%right NOT FLOOR CEIL POW ABS EXP LOG LN COS SIN TAN SQRT


%%
// VERIFIER LE TYPE DES ARGUMENTS DANS UN APPEL DE FONCTION ET CELUI DE L'ID QUI RECOIT
// reaexpr reafactor reaterm booexpr boofactor booterm %type <doubleval> REAL; %type <intval> TRUE FALSE boolean
program: STARTPRGM stmts ENDPRGM; // STARTPRGM declarations fcts stmts ENDPRGM; 
// %type <intval> headfct;
// %type <chstval> CHAR STRING charsandstrings 
// %type <id> returnfct;
/*groupstmts: BEGSTMT stmts ENDSTMT
;*/

/*declarations: 
|     declarations declaration SEMICOLON
;*/

stmts: comment stmt SEMICOLON
|   stmts comment stmt SEMICOLON
;

stmt:  assignexpr  
|   declaration     
/*|   IF booexpr THEN groupstmts elifstmt elsestmt ENDIF    {printf("CONDITIONAL STATEMENT");}
|   WHILE booexpr DO groupstmts ENDWHILE       {printf("LOOP STATEMENT");}
|   write
|   callfct*/
;

declaration: VAR ID COLON type    { printf("curr_scope = %d\n", curr_scope); install($2, $4, 0, 0, 0, curr_scope); printf("DECLARATION %s, %d \n", $2, $4);}

comment: 
|   COMMENT
;

assignexpr: ID ASSIGNMENT expr { context_check($1, curr_scope); if($3.type == INT_TYPE) {if(get_type($1, curr_scope) == INT_TYPE) { set_int_value($1, $3.ival, curr_scope); } else if(get_type($1, curr_scope) == REAL_TYPE) {set_real_value($1, $3.rval, curr_scope);} else {yyerror("Error assignment: bad type"); exit(1);}} else if($3.type == REAL_TYPE) {check_type($1, REAL_TYPE, curr_scope); set_real_value($1, $3.rval, curr_scope);} else if($3.type == BOOL_TYPE) {check_type($1, BOOL_TYPE, curr_scope); set_bool_value($1, $3.bval, curr_scope);} printf("ASSIGNED TO ID %s\n",$1); }
;

/*assignintexpr: ID ASSIGNMENT INT_TYPE intexpr { context_check($1, curr_scope); check_type($1, INT_TYPE, curr_scope); set_int_value($1, $4, curr_scope); printf("INTEGER %d ASSIGNED TO %s\n", $4, $1);}
;*/


expr: factor              {$$.type = $1.type;  if($1.type == INT_TYPE) {$$.ival = $1.ival;} else if($1.type == REAL_TYPE) {$$.rval = $1.rval;} else if($1.type == BOOL_TYPE) {$$.bval = $1.bval;} }
|   expr ADDOP factor     { if($1.type == INT_TYPE && $3.type == INT_TYPE) {$$.type = INT_TYPE; $$.ival = $1.ival+$3.ival;} else if($1.type == REAL_TYPE && $3.type == INT_TYPE) {$$.type = REAL_TYPE; $$.rval = $1.rval+(float)$3.ival;} else if($1.type == INT_TYPE && $3.type == REAL_TYPE) {$$.type = REAL_TYPE; $$.rval = (float)$1.ival+$3.rval;} else if($1.type == REAL_TYPE && $3.type == REAL_TYPE) {$$.type = REAL_TYPE; $$.rval = $1.rval+$3.rval;} else { yyerror("Must add numbers"); exit(1);} }
|   expr MINOP factor      { if($1.type == INT_TYPE && $3.type == INT_TYPE) {$$.type = INT_TYPE; $$.ival = $1.ival-$3.ival;} else if($1.type == REAL_TYPE && $3.type == INT_TYPE) {$$.type = REAL_TYPE; $$.rval = $1.rval-(float)$3.ival;} else if($1.type == INT_TYPE && $3.type == REAL_TYPE) {$$.type = REAL_TYPE; $$.rval = (float)$1.ival-$3.rval;} else if($1.type == REAL_TYPE && $3.type == REAL_TYPE) {$$.type = REAL_TYPE; $$.rval = $1.rval-$3.rval;} else { yyerror("Must substract numbers"); exit(1);} }
|   MINOP factor                { $$.type = $2.type; if($2.type == INT_TYPE) {$$.ival = -$2.ival;} else if($2.type == REAL_TYPE) {$$.rval = -$2.rval;} else {yyerror("- must be on number only"); exit(1);} }
|   expr GE factor      { $$.type = BOOL_TYPE; if($1.type == INT_TYPE && $3.type == INT_TYPE) { $$.bval = $1.ival >= $3.ival; } else if($1.type == REAL_TYPE && $3.type == INT_TYPE) { $$.bval = $1.rval >= $3.ival; } else if($1.type == INT_TYPE && $3.type == REAL_TYPE) { $$.bval = $1.ival >= $3.rval; } else if($1.type == REAL_TYPE && $3.type == REAL_TYPE) { $$.bval = $1.rval >= $3.rval; } else {yyerror("Must make boolean op on numbers"); exit(1);}}  
|   expr LE factor      { $$.type = BOOL_TYPE; if($1.type == INT_TYPE && $3.type == INT_TYPE) { $$.bval = $1.ival <= $3.ival; } else if($1.type == REAL_TYPE && $3.type == INT_TYPE) { $$.bval = $1.rval <= $3.ival; } else if($1.type == INT_TYPE && $3.type == REAL_TYPE) { $$.bval = $1.ival <= $3.rval; } else if($1.type == REAL_TYPE && $3.type == REAL_TYPE) { $$.bval = $1.rval <= $3.rval; } else {yyerror("Must make boolean op on numbers"); exit(1);}}  
|   expr GT factor     { $$.type = BOOL_TYPE; if($1.type == INT_TYPE && $3.type == INT_TYPE) { $$.bval = $1.ival > $3.ival; } else if($1.type == REAL_TYPE && $3.type == INT_TYPE) { $$.bval = $1.rval > $3.ival; } else if($1.type == INT_TYPE && $3.type == REAL_TYPE) { $$.bval = $1.ival > $3.rval; } else if($1.type == REAL_TYPE && $3.type == REAL_TYPE) { $$.bval = $1.rval > $3.rval; } else {yyerror("Must make boolean op on numbers"); exit(1);}}  
|   expr LT factor     { $$.type = BOOL_TYPE; if($1.type == INT_TYPE && $3.type == INT_TYPE) { $$.bval = $1.ival < $3.ival; } else if($1.type == REAL_TYPE && $3.type == INT_TYPE) { $$.bval = $1.rval < $3.ival; } else if($1.type == INT_TYPE && $3.type == REAL_TYPE) { $$.bval = $1.ival < $3.rval; } else if($1.type == REAL_TYPE && $3.type == REAL_TYPE) { $$.bval = $1.rval < $3.rval; } else {yyerror("Must make boolean op on numbers"); exit(1);}}  
|   expr EQ factor     { $$.type = BOOL_TYPE; if($1.type == INT_TYPE && $3.type == INT_TYPE) { $$.bval = $1.ival == $3.ival; } else if($1.type == REAL_TYPE && $3.type == INT_TYPE) { $$.bval = $1.rval == $3.ival; } else if($1.type == INT_TYPE && $3.type == REAL_TYPE) { $$.bval = $1.ival == $3.rval; } else if($1.type == REAL_TYPE && $3.type == REAL_TYPE) { $$.bval = $1.rval == $3.rval; } else {yyerror("Must make boolean op on numbers"); exit(1);}}  
|   expr NE factor   { $$.type = BOOL_TYPE; if($1.type == INT_TYPE && $3.type == INT_TYPE) { $$.bval = $1.ival != $3.ival; } else if($1.type == REAL_TYPE && $3.type == INT_TYPE) { $$.bval = $1.rval != $3.ival; } else if($1.type == INT_TYPE && $3.type == REAL_TYPE) { $$.bval = $1.ival != $3.rval; } else if($1.type == REAL_TYPE && $3.type == REAL_TYPE) { $$.bval = $1.rval != $3.rval; } else {yyerror("Must make boolean op on numbers"); exit(1);}}  
|   expr AND factor   { $$.type = BOOL_TYPE; if($1.type == BOOL_TYPE && $3.type == BOOL_TYPE) {$$.bval = $1.bval && $3.bval;} else {yyerror("Must make AND operation on boolean");}}
|   expr OR factor    { $$.type = BOOL_TYPE; if($1.type == BOOL_TYPE && $3.type == BOOL_TYPE) {$$.bval = $1.bval || $3.bval;} else {yyerror("Must make OR operation on boolean");}}
|   NOT factor            { $$.type = BOOL_TYPE; if($2.type == BOOL_TYPE) {$$.bval = (!$2.bval); } else {yyerror("Must make NOT operation on boolean");}}
;

factor: term              {$$.type = $1.type;  if($1.type == INT_TYPE) {$$.ival = $1.ival;} else if($1.type == REAL_TYPE) {$$.rval = $1.rval;} else if($1.type == BOOL_TYPE) {$$.bval = $1.bval;} }
|   factor MULOP term    { if($1.type == INT_TYPE && $3.type == INT_TYPE) {$$.type = INT_TYPE; $$.ival = $1.ival*$3.ival;} else if($1.type == REAL_TYPE && $3.type == INT_TYPE) {$$.type = REAL_TYPE; $$.rval = $1.rval*(float)$3.ival;} else if($1.type == INT_TYPE && $3.type == REAL_TYPE) {$$.type = REAL_TYPE; $$.rval = (float)$1.ival*$3.rval;} else if($1.type == REAL_TYPE && $3.type == REAL_TYPE) {$$.type = REAL_TYPE; $$.rval = $1.rval*$3.rval;} else { yyerror("Must multiply numbers"); exit(1);} }
|   factor DIVOP term    { if($1.type == INT_TYPE && $3.type == INT_TYPE) {$$.type = INT_TYPE; $$.ival = $1.ival/$3.ival;} else if($1.type == REAL_TYPE && $3.type == INT_TYPE) {$$.type = REAL_TYPE; $$.rval = $1.rval/(float)$3.ival;} else if($1.type == INT_TYPE && $3.type == REAL_TYPE) {$$.type = REAL_TYPE; $$.rval = (float)$1.ival/$3.rval;} else if($1.type == REAL_TYPE && $3.type == REAL_TYPE) {$$.type = REAL_TYPE; $$.rval = (float) $1.rval/$3.rval;} else { yyerror("Must divide numbers"); exit(1);} }
|   factor DIV term      { $$.type = INT_TYPE; if($1.type == INT_TYPE && $3.type == INT_TYPE) {$$.ival = $1.ival/$3.ival;} else if($1.type == REAL_TYPE && $3.type == INT_TYPE) {$$.ival = (int) $1.rval/$3.ival;} else if($1.type == INT_TYPE && $3.type == REAL_TYPE) {$$.ival = (int)$1.ival/$3.rval;} else if($1.type == REAL_TYPE && $3.type == REAL_TYPE) {$$.ival = (int) $1.rval/$3.rval;} else { yyerror("Must divide numbers"); exit(1);} }
|   factor MOD term      { if($1.type == INT_TYPE && $3.type == INT_TYPE) {$$.type = INT_TYPE; $$.ival = (int)fmod($1.ival, $3.ival);} else if($1.type == REAL_TYPE && $3.type == INT_TYPE) {$$.type = REAL_TYPE; $$.rval = fmod($1.rval, (float)$3.ival);} else if($1.type == INT_TYPE && $3.type == REAL_TYPE) {$$.type = REAL_TYPE; $$.rval = fmod((float)$1.ival, $3.rval);} else if($1.type == REAL_TYPE && $3.type == REAL_TYPE) {$$.type = REAL_TYPE; $$.rval = fmod($1.rval, $3.rval);} else { yyerror("Must divide numbers"); exit(1);}}
;

term: ID          { $$.type = get_type($1, curr_scope); if(get_type($1, curr_scope) == INT_TYPE) { $$.ival = get_int_value($1, curr_scope);} else if(get_type($1, curr_scope) == REAL_TYPE) {$$.rval = get_real_value($1, curr_scope);} else if(get_type($1, curr_scope) == BOOL_TYPE) {$$.bval = get_bool_value($1, curr_scope);}}
|      INTEGER             {$$.type = $1.type; $$.ival = $1.ival;}
|     REAL                  {$$.type = $1.type; $$.rval = $1.rval;}
|     TRUE                  {$$.type = $1.type; $$.bval = 1;}
|     FALSE                 {$$.type = $1.type; $$.bval = 0;}
|    OPENPAR expr CLOSEPAR  {$$ = $2; }
|   ABS OPENPAR expr CLOSEPAR {$$.type = $3.type; if($3.type == INT_TYPE) {$$.ival = (int)abs($3.ival);} else if($3.type == REAL_TYPE) {$$.rval = abs($3.rval);} }
|   POW OPENPAR expr COMMA expr CLOSEPAR      { if($3.type == INT_TYPE && $5.type == INT_TYPE) {$$.type = INT_TYPE; $$.ival = pow($3.ival, $5.ival);} else if($3.type == REAL_TYPE && $5.type == INT_TYPE) {$$.type = REAL_TYPE; $$.rval = pow($3.rval, (float)$5.ival);} else if($3.type == INT_TYPE && $5.type == REAL_TYPE) {$$.type = REAL_TYPE; $$.rval = pow((float)$3.ival, $5.rval);} else if($3.type == REAL_TYPE && $5.type == REAL_TYPE) {$$.type = REAL_TYPE; $$.rval = pow($3.rval, $5.rval);} else { yyerror("Must power numbers"); exit(1);} }
|   SQRT OPENPAR expr CLOSEPAR {$$.type = $3.type; if($3.type == INT_TYPE) {if($3.ival >= 0) {$$.ival = (int)sqrt($3.ival);}} else if($3.type == REAL_TYPE) {if($3.rval >= 0) {$$.rval = sqrt($3.rval);}} else{yyerror("Cannot make sqrt on negative number");exit(1);}}
|   EXP OPENPAR expr CLOSEPAR {$$.type = $3.type; if($3.type == INT_TYPE) {$$.ival = (int)exp($3.ival);} else if($3.type == REAL_TYPE) {$$.rval = exp($3.rval);} }
|   LOG OPENPAR expr CLOSEPAR {$$.type = $3.type; if($3.type == INT_TYPE) {if($3.ival >= 0) {$$.ival = (int)log10($3.ival);}} else if($3.type == REAL_TYPE) {if($3.rval >= 0) {$$.rval = log10($3.rval);}} else{yyerror("Cannot make log on negative number");exit(1);}}
|   LN OPENPAR expr CLOSEPAR  {$$.type = $3.type; if($3.type == INT_TYPE) {if($3.ival >= 0) {$$.ival = (int)log($3.ival);}} else if($3.type == REAL_TYPE) {if($3.rval >= 0) {$$.rval = log($3.rval);}} else{yyerror("Cannot make ln on negative number");exit(1);}}
|   FLOOR OPENPAR expr CLOSEPAR {$$.type = INT_TYPE; if($3.type == INT_TYPE) {$$.ival = $3.ival;} else if($3.type == REAL_TYPE) {$$.ival = (int)floor($3.rval);} else {yyerror("Must floor on number");} }
|   CEIL OPENPAR expr CLOSEPAR  {$$.type = INT_TYPE; if($3.type == INT_TYPE) {$$.ival = $3.ival;} else if($3.type == REAL_TYPE) {$$.ival = (int)ceil($3.rval);} else {yyerror("Must ceil on number");} }
|   COS OPENPAR expr CLOSEPAR  {$$.type = REAL_TYPE; if($3.type == REAL_TYPE) {$$.rval = cos($3.rval);} else {yyerror("Must make cos on real");}}
|   SIN OPENPAR expr CLOSEPAR  {$$.type = REAL_TYPE; if($3.type == REAL_TYPE) {$$.rval = sin($3.rval);} else {yyerror("Must make sin on real");}}
|   TAN OPENPAR expr CLOSEPAR  {$$.type = REAL_TYPE; if($3.type == REAL_TYPE) {$$.rval = tan($3.rval);} else {yyerror("Must make tan on real");}}
;

/*reaexpr: reafactor        {$$ = $1; printf("MY REAL FACTOR = %f\n", $$);}
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
;*/


type: INT_TYPE   {$$ = INT_TYPE;}
|   REAL_TYPE     {$$ = REAL_TYPE;}
|   CHAR_TYPE     {$$ = CHAR_TYPE;}
|   STRING_TYPE   {$$ = STRING_TYPE;}
|   BOOL_TYPE     {$$ = BOOL_TYPE;}
;

/*elifstmt: 
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

fct:  headfct groupstmts returnfct    { printf("curr_scope finishing = %d\n", curr_scope); check_type($3, $1, curr_scope+1); }
;

headfct: FCT ID OPENPAR parameters CLOSEPAR COLON type  { printf("%d\n", curr_scope); install($2, $7, 0, 0, 0, curr_scope); printf("FUNTCION DECLARED"); curr_scope++; printf("curr_scope = %d\n", curr_scope); $$ = $7; }
;

returnfct: RETURN ID   {curr_scope--;  $$ = $2;}
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
;*/

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