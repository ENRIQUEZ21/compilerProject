%{
  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include <math.h>
  #include "ST.h"
  #define YYDEBUG 1
  int yylex(void);
  void yyerror(char *);


  void install ( char *sym_name, int type, int int_val, double real_val, int bool_val)
  {
    symrec *s;
    symrec *i;
    s = getsym (sym_name);
    if (s == 0) {
      s = putsym (sym_name, type, int_val, real_val, bool_val);     
      i = getsym(sym_name);
    } else { 
      printf( "%s is already defined\n", sym_name );
    }
  }

  void context_check( char *sym_name ) { 
    symrec *identifier;
    identifier = getsym( sym_name );
    if ( identifier == 0 ) { 
      printf( "%s", sym_name );
      printf( "%s\n", " is an undeclared identifier" );
    }
  }

  void check_type( char *sym_name, int type) { 
    symrec *identifier;
    identifier = getsym( sym_name );
    if(identifier->type != type) {
      printf( "%s", sym_name );
      if(type == 259) {
        printf( "%s\n", " is not an integer" );
      } else if(type == 260) {
        printf( "%s\n", " is not a real" );
      } else if(type == 263) {
        printf( "%s\n", " is not a boolean" );
      }
      exit(1);
    }
    
  }

  void set_real_value(char *sym_name, double real_value) {
    setrealval(sym_name, real_value);
  }

  double get_real_value(char *sym_name) {
    return getrealval(sym_name);
  }

  void set_bool_value(char *sym_name, int bool_value) {
    setboolval(sym_name, bool_value);
  }

  int get_bool_value(char *sym_name) {
    return getboolval(sym_name);
  }

%}

%union semrec 
{
  double doubleval;
  int intval; 
  int boolval;
  char *id;
  struct lbs *lbls; 
}

%token <id> ID

%type <doubleval> number;
%type <doubleval> ariexpr;
%type <doubleval> term;
%type <doubleval> factor;
%type <doubleval> INTEGER;
%type <doubleval> REAL;

%type <intval> INT_TYPE;
%type <intval> REAL_TYPE;
%type <intval> CHAR_TYPE;
%type <intval> STRING_TYPE;
%type <intval> BOOL_TYPE;

%type <intval> type;



%type <boolval> TRUE FALSE;

%type <doubleval> assignariexpr;
%type <boolval> assignboolexpr;


%type <boolval> boolexpr;
%type <boolval> boolean;

%token INT_TYPE;
%token REAL_TYPE;
%token CHAR_TYPE;
%token STRING_TYPE;
%token BOOL_TYPE;

%token WS
%token LINE
%token COMMENT
%token STARTPRGM ENDPRGM 
%token IF THEN ELIF ELSE ENDIF WHILE DO ENDWHILE BEGSTMT ENDSTMT CLASS ENDCLASS WRITE
%token COMMA DBPTS OPENPAR CLOSEPAR OPENBRA CLOSEBRA SEMICOLON DOT
%token INTEGER REAL CHAR STRING TRUE FALSE MODIFIER VAR NEWINSTCLASS
%token FCT RETURN
%token AND OR 
%left ADDOP MINOP MULOP DIVOP DIV MOD ASSIGNMENT LE GE LT GT EQ NE 
%left RAND TAN COS SIN FLOOR CEIL
%right NOT ABS POW SQRT EXP LOG LN 

%%
program: STARTPRGM stmts ENDPRGM; // classes fcts 

stmts: 
|   stmts stmt //  comment
;

// groupstmts: BEGSTMT stmts ENDSTMT

stmt: assignboolexpr  
|   VAR ID DBPTS type    { install($2, $4, 0, 0, 0); printf("DECLARATION\n");}
/*|   IF boolexpr THEN groupstmts elifstmt elsestmt ENDIF    {printf("CONDITIONAL STATEMENT");}
|   WHILE boolexpr DO groupstmts ENDWHILE       {printf("LOOP STATEMENT");}
|   WRITE expr
|   VAR vardeclar DBPTS TYPE    {printf("DECLARATION");}
|   callfct
|   callclass*/
;

assignboolexpr: ID ASSIGNMENT boolexpr  { context_check($1); check_type($1, BOOL_TYPE); set_bool_value($1, $3); $$ = $3; printf("BOOL EXPRESSION: SIMPLE STATEMENT\n");}
;

assignariexpr: ID ASSIGNMENT ariexpr   { context_check($1); check_type($1, REAL_TYPE); set_real_value($1, $3); $$ = $3; printf("ARITHM EXPRESSION: SIMPLE STATEMENT\n");}
; 

 


type: INT_TYPE   {$$ = INT_TYPE;}
|   REAL_TYPE     {$$ = REAL_TYPE;}
|   CHAR_TYPE     {$$ = CHAR_TYPE;}
|   STRING_TYPE   {$$ = STRING_TYPE;}
|   BOOL_TYPE     {$$ = BOOL_TYPE;}
;

number: INTEGER             
|   REAL                    
;

ariexpr: factor
|   ariexpr ADDOP factor { $$ = $1 + $3; printf("result = %f\n", $$);}
|   ariexpr MINOP factor { $$ = $1 - $3; printf("result = %f\n", $$);}
;

factor: term
|   factor MULOP term    { $$ = $1 * $3; printf("result = %f\n", $$);}
|   factor DIVOP term    {if($3 != 0) {$$ = $1 / $3; printf("result = %f\n", $$);} else {yyerror("Illegal division by 0");exit(1);} }
|   factor DIV term      { if($3 != 0){	$$ = floor($1 / $3); printf("result = %f\n", $$);} else{yyerror("Illegal division by 0");exit(1);}};
|   factor MOD term      { $$ = fmod($1, $3); printf("result = %f\n", $$);};
;

term:  ID                      { check_type($1, REAL_TYPE); $$ = get_real_value($1); printf("MY REAL = %f\n", $$); }
|    REAL
|    OPENPAR ariexpr CLOSEPAR  {$$ = $2; printf("result = %f\n", $$);}
|   ABS OPENPAR ariexpr CLOSEPAR {$$ = abs($3); printf("result = %f\n", $$);}
|   POW OPENPAR ariexpr COMMA ariexpr CLOSEPAR {$$ = pow($3, $5); printf("result = %f\n", $$);}
|   SQRT OPENPAR ariexpr CLOSEPAR { if($3 >= 0) {$$ = sqrt($3); printf("result = %f\n", $$);} else{yyerror("Cannot make sqrt on negative number");exit(1);}}
|   EXP OPENPAR ariexpr CLOSEPAR {$$ = exp($3); printf("result = %f\n", $$);}
|   LOG OPENPAR ariexpr CLOSEPAR {if($3 >= 0) {$$ = log10($3); printf("result = %f\n", $$);} else {yyerror("Cannot make log on negative number");exit(1);}}
|   LN OPENPAR ariexpr CLOSEPAR  {if($3 >= 0) {$$ = log($3); printf("result = %f\n", $$);} else {yyerror("Cannot make ln on negative number");exit(1);}}
|   FLOOR OPENPAR ariexpr CLOSEPAR {$$ = floor($3); printf("result = %f\n", $$);}
|   CEIL OPENPAR ariexpr CLOSEPAR  {$$ = ceil($3); printf("result = %f\n", $$);}
|   COS OPENPAR ariexpr CLOSEPAR  {$$ = cos($3); printf("result = %f\n", $$);}
|   SIN OPENPAR ariexpr CLOSEPAR  {$$ = sin($3); printf("result = %f\n", $$);}
|   TAN OPENPAR ariexpr CLOSEPAR  {$$ = tan($3); printf("result = %f\n", $$);}
|   RAND OPENPAR ariexpr CLOSEPAR  {srand(time(NULL));; $$ = ((float)rand()/(float)RAND_MAX) * (float)$3; printf("result = %f\n", $$);}
;


boolexpr: ID                { check_type($1, BOOL_TYPE); $$ = get_bool_value($1); printf("MY BOOL = %d\n", $$); }
|   boolean                   
|   OPENPAR boolexpr CLOSEPAR   {$$ = $2; printf("result = %d\n", $$);}
|   ariexpr GE ariexpr      { $$ = $1 >= $3; printf("result = %d\n", $$);};  
|   ariexpr LE ariexpr      { $$ = $1 <= $3; printf("result = %d\n", $$);};
|   ariexpr GT ariexpr      { $$ = $1 > $3; printf("result = %d\n", $$);};
|   ariexpr LT ariexpr      { $$ = $1 < $3; printf("result = %d\n", $$);};
|   ariexpr EQ ariexpr      { $$ = $1 == $3; printf("result = %d\n", $$);};
|   ariexpr NE ariexpr      { $$ = $1 != $3; printf("result = %d\n", $$);};
|   boolexpr AND boolexpr   { $$ = $1 && $3; printf("result = %d\n", $$);};
|   boolexpr OR boolexpr    { $$ = $1 || $3; printf("result = %d\n", $$);};
|   NOT boolexpr            { $$ = (!$2); printf("result = %d\n", $$);};
;

boolean: TRUE               { $$ = 1; printf("BOOL VALUE = %d\n", $$);}
|       FALSE               { $$ = 0; printf("BOOL VALUE = %d\n", $$);}
;
/*
elifstmt: 
|   elifstmt ELIF boolexpr THEN groupstmts
;

elsestmt:
|   ELSE groupstmts
;

vardeclar: ID
|   ID COMMA vardeclar
;

varinstdeclar: instances
|   instances COMMA varinstdeclar
;

comment: 
|   COMMENT
;

instances: ID
|   INTEGER
|   REAL
|   STRING
|   CHAR
|   BOOLEAN
;

fcts: 
|   fcts FCT ID OPENPAR vardeclar CLOSEPAR DBPTS TYPE groupstmts RETURN instances 
;

classes:
|   classes MODIFIER CLASS ID fcts groupstmts ENDCLASS
;

callfct: ID ASSIGNMENT ID OPENPAR varinstdeclar CLOSEPAR        
|   ID ASSIGNMENT ID DOT ID OPENPAR varinstdeclar CLOSEPAR      
;

callclass: ID ASSIGNMENT NEWINSTCLASS ID;*/

%%

/*yylex() {
    int c;
    c = getchar();
    if (isdigit(c)) {
    yylval = c-'0';
    return DIGIT;
    }
    return c;
}*/


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