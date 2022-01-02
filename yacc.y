%{
  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include <math.h>
  #include "ST.h"
  #define YYDEBUG 1
  int yylex(void);
  void yyerror(char *);

  install ( char *sym_name )
  {
    symrec *s;
    s = getsym (sym_name);
    if (s == 0)
      s = putsym (sym_name);
    else { 
      printf( "%s is already defined\n", sym_name );
    }
  }

  context_check( char *sym_name ) { 
    symrec *identifier;
    identifier = getsym( sym_name );
    if ( identifier == 0 ) { 
      printf( "%s", sym_name );
      printf( "%s\n", " is an undeclared identifier" );
    }
  }

%}

%union semrec 
{
  double doubleval;
  int intval; 
  char *id;
  struct lbs *lbls; 
}

%token <id> ID

%type <intval> ariexpr;
%type <intval> term;
%type <intval> factor;
%type <intval> INTEGER;

%token WS
%token LINE
%token COMMENT
%token STARTPRGM ENDPRGM 
%token IF THEN ELIF ELSE ENDIF WHILE DO ENDWHILE BEGSTMT ENDSTMT CLASS ENDCLASS WRITE
%token COMMA DBPTS OPENPAR CLOSEPAR OPENBRA CLOSEBRA SEMICOLON DOT
%token INTEGER REAL CHAR STRING BOOLEAN MODIFIER TYPE VAR NEWINSTCLASS
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

stmt: ID ASSIGNMENT ariexpr        {printf("SIMPLE STATEMENT");}
/*|   IF boolexpr THEN groupstmts elifstmt elsestmt ENDIF    {printf("CONDITIONAL STATEMENT");}
|   WHILE boolexpr DO groupstmts ENDWHILE       {printf("LOOP STATEMENT");}
|   WRITE expr
|   VAR vardeclar DBPTS TYPE    {printf("DECLARATION");}
|   callfct
|   callclass*/
;

/*expr: ariexpr
|   boolexpr
;

number: INTEGER             
|   REAL                    
;
*/
ariexpr: factor
|   ariexpr ADDOP factor { $$ = $1 + $3; printf("result = %d\n", $$);}
|   ariexpr MINOP factor { $$ = $1 - $3; printf("result = %d\n", $$);}
;

factor: term
|   factor MULOP term    { $$ = $1 * $3; printf("result = %d\n", $$);}
|   factor DIVOP term    {if($3 != 0) {$$ = $1 / $3; printf("result = %d\n", $$);} else {yyerror("Illegal division by 0");exit(1);} }
|   factor DIV term      { if($3 != 0){	$$ = floor($1 / $3); printf("result = %d\n", $$);} else{yyerror("Illegal division by 0");exit(1);}};
|   factor MOD term      { $$ = fmod($1, $3); printf("result = %d\n", $$);};
;

term:    INTEGER
|    OPENPAR ariexpr CLOSEPAR  {$$ = $2; printf("result = %d\n", $$);}
|   ABS OPENPAR ariexpr CLOSEPAR {$$ = abs($3); printf("result = %d\n", $$);}
|   POW OPENPAR ariexpr COMMA ariexpr CLOSEPAR {$$ = pow($3, $5); printf("result = %d\n", $$);}
|   SQRT OPENPAR ariexpr CLOSEPAR { if($3 >= 0) {$$ = sqrt($3); printf("result = %d\n", $$);} else{yyerror("Cannot make sqrt on negative number");exit(1);}}
|   EXP OPENPAR ariexpr CLOSEPAR {$$ = exp($3); printf("result = %d\n", $$);}
|   LOG OPENPAR ariexpr CLOSEPAR {if($3 >= 0) {$$ = log10($3); printf("result = %d\n", $$);} else {yyerror("Cannot make log on negative number");exit(1);}}
|   LN OPENPAR ariexpr CLOSEPAR  {if($3 >= 0) {$$ = log($3); printf("result = %d\n", $$);} else {yyerror("Cannot make ln on negative number");exit(1);}}
|   FLOOR OPENPAR ariexpr CLOSEPAR {$$ = floor($3); printf("result = %d\n", $$);}
|   CEIL OPENPAR ariexpr CLOSEPAR  {$$ = ceil($3); printf("result = %d\n", $$);}
|   COS OPENPAR ariexpr CLOSEPAR  {$$ = cos($3); printf("result = %d\n", $$);}
|   SIN OPENPAR ariexpr CLOSEPAR  {$$ = sin($3); printf("result = %d\n", $$);}
|   TAN OPENPAR ariexpr CLOSEPAR  {$$ = tan($3); printf("result = %d\n", $$);}
|   RAND OPENPAR ariexpr CLOSEPAR  {srand(time(NULL));; $$ = ((float)rand()/(float)RAND_MAX) * (float)$3; printf("result = %d\n", $$);}
;


/*boolexpr: BOOLEAN
|   OPENPAR boolexpr CLOSEPAR   {$$ = $2; printf("result = %d\n", $$);}
|   ariexpr GE ariexpr      { $$ = $1 >= $3; printf("result = %d\n", $$);};  
|   ariexpr LE ariexpr      { $$ = $1 <= $3; printf("result = %d\n", $$);};
|   ariexpr GT ariexpr      { $$ = $1 > $3; printf("result = %d\n", $$);};
|   ariexpr LT ariexpr      { $$ = $1 < $3; printf("result = %d\n", $$);};
|   ariexpr EQ ariexpr      { $$ = $1 == $3; printf("result = %d\n", $$);};
|   ariexpr NE ariexpr      { $$ = $1 != $3; printf("result = %d\n", $$);};
|   boolexpr AND boolexpr   { $$ = $1 && $3; printf("result = %d\n", $$);};
|   boolexpr OR boolexpr    { $$ = $1 || $3; printf("result = %d\n", $$);};
|   NOT boolexpr            { $$ = ($1 == $0); printf("result = %d\n", $$);};
;
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