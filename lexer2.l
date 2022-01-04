%{
#include "yacc2.tab.h"
#include <string.h>
#include <stdlib.h>
void yyerror(char *);


int cnt_line = 0;


%}
delim [\t ]
WS {delim}+
line 			\n
letter [a-zA-Z]
digit  [0-9]
alphanum {letter}|{digit}|_
punctuations ","|"."|":"|"("|")"|"{"|"}"|";"|"_"|"!"|"~"|"@"|"="|"&"|"["|"]"|"'"|"`"|"%"|"$"|"€"|"?"|"#"|"+"|"-"|"*"|"/"|"<"|">"
identifier {letter}{alphanum}*
integer [-]?{digit}+
real [-]?{digit}+\.{digit}*
char '({alphanum}|{WS}|{punctuations})*'
string \"({alphanum}|{WS}|{punctuations})*\"
boolean true|false
comment  \{({alphanum}|{WS}|{punctuations})*\}
type integer|char|string|boolean|real
%%

start return STARTPRGM;
end   return ENDPRGM;
","  return COMMA; 
":"  return DBPTS;
"("  return OPENPAR;
")"  return CLOSEPAR;
"+"  return ADDOP; 
"-"  return MINOP; 
"*"  return MULOP;
"/"  return DIVOP;
div  return DIV;
mod  return MOD;
abs  return ABS;
pow  return POW;
{integer}  yylval.intval = atoi( yytext ); return INTEGER;
"integer"   return INT_TYPE;
"real"      return REAL_TYPE;
"char"      return CHAR_TYPE;
"string"    return STRING_TYPE;
"boolean"   return BOOL_TYPE;
var     return VAR;
":="        return ASSIGNMENT;    
{identifier}    yylval.id = (char *) strdup(yytext); return(ID); 
{WS}						;
{line}						++cnt_line;
.							{return(yytext[0]);}

%%

// Supplementary C functions
int yywrap(void) {return 1;}