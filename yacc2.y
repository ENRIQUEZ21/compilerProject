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

  void set_int_value(char *sym_name, int int_value) {
    setintval(sym_name, int_value);
  }

  int get_int_value(char *sym_name) {
    return getintval(sym_name);
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

%token <id> ID;

%token INTEGER INT_TYPE REAL_TYPE CHAR_TYPE STRING_TYPE BOOL_TYPE;
%type <intval> INTEGER; 
%type <intval> intexpr; 
%type <intval> intfactor; 
%type <intval> intterm; 
%type <intval> assignintexpr; 
%type <intval> type INT_TYPE REAL_TYPE CHAR_TYPE STRING_TYPE BOOL_TYPE;


%token <doubleval> REAL;
%token VAR DBPTS OPENPAR CLOSEPAR COMMA 
%token STARTPRGM ENDPRGM 


%left ADDOP MINOP MULOP DIVOP DIV MOD ASSIGNMENT
%left FLOOR CEIL POW ABS 

%%

program: STARTPRGM stmts ENDPRGM; 

stmts: 
|   stmts stmt 
;

stmt: assignintexpr  
|   VAR ID DBPTS type    { install($2, $4, 0, 0, 0); printf("DECLARATION %s, %d \n", $2, $4);}
;
/*
assignexpr: assignintexpr
|           assignrealexpr
;
*/
assignintexpr: ID ASSIGNMENT intexpr  { set_int_value($1, $3); printf("INTEGER SET = %d\n", $3);}  
;
/*
assignrealexpr: ID ASSIGNMENT realexpr  { set_real_value($1, $3); printf("REAL SET = %f\n", $3);} 
; */

intexpr: intfactor
|       intexpr ADDOP intfactor  { $$ = $1 + $3; printf("result adding = %d, with $1 = %d and $3 = %d\n", $$, $1, $3);}
|       intexpr MINOP intfactor  { $$ = $1 - $3; printf("result = %d\n", $$);}
|       MINOP intfactor  { $$ = - $2; printf("result = %d\n", $$);}
;

intfactor: intterm              { $$ = $1;}
|   intfactor MULOP intterm    { $$ = $1 * $3; printf("result = %d\n", $$);}
|   intfactor DIVOP intterm    { if($3 != 0) {$$ = $1 / $3; printf("result = %d\n", $$);} else {yyerror("Illegal division by 0");exit(1);} }
|   intfactor DIV intterm      { if($3 != 0){	$$ = floor($1 / $3); printf("result = %d\n", $$);} else{yyerror("Illegal division by 0");exit(1);}};
|   intfactor MOD intterm      { $$ = fmod($1, $3); printf("result = %d\n", $$);};
;

intterm: ID  { check_type($1, INT_TYPE); $$ = get_int_value($1); printf("ID %s HAS TYPE INTEGER CHECKED AND VALUE = %d \n", $1, $$); }
|       INTEGER     { $$ = $1; printf("MY INTEGER = %d\n", $$); }
|    OPENPAR intexpr CLOSEPAR  {$$ = $2; printf("result = %d\n", $$);}
|   ABS OPENPAR intexpr CLOSEPAR {$$ = abs($3); printf("result = %d\n", $$);}
|   POW OPENPAR intexpr COMMA intexpr CLOSEPAR {$$ = pow($3, $5); printf("result = %d\n", $$);}
;

/*
realexpr: realfactor
|       realexpr ADDOP realfactor  { $$ = $1 + $3; printf("result adding = %f, with $1 = %f and $3 = %f\n", $$, $1, $3);}
|       realexpr MINOP realfactor  { $$ = $1 - $3; printf("result = %f\n", $$);}
|       MINOP realfactor  { $$ = - $2; printf("result = %f\n", $$);}
;

realfactor: realterm              { $$ = $1;}
|   realfactor MULOP realterm    { $$ = $1 * $3; printf("result = %f\n", $$);}
|   realfactor DIVOP realterm    { if($3 != 0) {$$ = $1 / $3; printf("result = %f\n", $$);} else {yyerror("Illegal division by 0");exit(1);} }
|   realfactor DIV realterm      { if($3 != 0){	$$ = floor($1 / $3); printf("result = %f\n", $$);} else{yyerror("Illegal division by 0");exit(1);}};
|   realfactor MOD realterm      { $$ = fmod($1, $3); printf("result = %f\n", $$);};
;

realterm: ID  { check_type($1, REAL_TYPE); $$ = get_real_value($1); printf("ID %s HAS TYPE REAL CHECKED AND VALUE = %f \n", $1, $$); }
|       REAL     { $$ = $1; printf("MY REAL = %f\n", $$); }
|    OPENPAR realexpr CLOSEPAR  {$$ = $2; printf("result = %f\n", $$);}
|   ABS OPENPAR realexpr CLOSEPAR {$$ = abs($3); printf("result = %f\n", $$);}
|   POW OPENPAR realexpr COMMA realexpr CLOSEPAR {$$ = pow($3, $5); printf("result = %f\n", $$);}
;*/



type: INT_TYPE   {$$ = INT_TYPE;}
|   REAL_TYPE     {$$ = REAL_TYPE;}
|   CHAR_TYPE     {$$ = CHAR_TYPE;}
|   STRING_TYPE   {$$ = STRING_TYPE;}
|   BOOL_TYPE     {$$ = BOOL_TYPE;}
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