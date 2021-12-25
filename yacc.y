%{
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int yylex(void);
void yyerror(char *);

%}

%code requires
  {
    #define YYSTYPE double
  }

%token ID
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
%right NOT ABS POW SQRT EXP LOG LN

%%
program: STARTPRGM classes fcts stmts ENDPRGM;

stmts: 
|   stmts stmt comment
;

groupstmts: BEGSTMT stmts ENDSTMT

stmt: ID ASSIGNMENT expr        {printf("SIMPLE STATEMENT");}
|   IF boolexpr THEN groupstmts elifstmt elsestmt ENDIF    {printf("CONDITIONAL STATEMENT");}
|   WHILE boolexpr DO groupstmts ENDWHILE       {printf("LOOP STATEMENT");}
|   WRITE expr
|   VAR vardeclar DBPTS TYPE    {printf("DECLARATION");}
|   callfct
|   callclass
;

expr: ariexpr
|   boolexpr
;

number: INTEGER             { $$ = $1;}
|   REAL                    { $$ = $1; printf("REAL = %f\n", $$)} 
;
ariexpr: number
|   ID
|   ariexpr ADDOP ariexpr    { $$ = $1 + $3; printf("result = %f\n", $$);};
|   ariexpr MINOP ariexpr    { $$ = $1 - $3; printf("result = %f\n", $$);};
|   ariexpr MULOP ariexpr    { $$ = $1 * $3; printf("result = %f\n", $$);};
|   ariexpr DIVOP ariexpr    { $$ = $1 / $3; printf("result = %f\n", $$);};
|   ariexpr DIV ariexpr
|   ariexpr MOD ariexpr
|   OPENPAR ariexpr CLOSEPAR   {$$ = $2; printf("result = %f\n", $$);}
|   ABS OPENPAR ariexpr CLOSEPAR {$$ = abs($3); printf("result = %f\n", $$);}
|   POW OPENPAR ariexpr COMMA ariexpr CLOSEPAR {$$ = pow($3, $5); printf("result = %f\n", $$);}
|   SQRT OPENPAR ariexpr CLOSEPAR {$$ = sqrt($3); printf("result = %f\n", $$);}
|   EXP OPENPAR ariexpr CLOSEPAR {$$ = exp($3); printf("result = %f\n", $$);}
|   LOG OPENPAR ariexpr CLOSEPAR {$$ = log10($3); printf("result = %f\n", $$);}
|   LN OPENPAR ariexpr CLOSEPAR {$$ = log($3); printf("result = %f\n", $$);}
;

boolexpr: BOOLEAN
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

callclass: ID ASSIGNMENT NEWINSTCLASS ID;

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