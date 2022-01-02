%{
#include "yacc.tab.h"
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
{comment}  return COMMENT;
","  return COMMA; 
":"  return DBPTS;
"("  return OPENPAR;
")"  return CLOSEPAR;
"{"  return OPENBRA;
"}"  return CLOSEBRA;
";"  return SEMICOLON;
"."  return DOT;
"==" return EQ;
"<=" return LE;
">=" return GE;
"<"  return LT;
">"  return GT;
"<>" return NE;
and  return AND;
or   return OR;
not  return NOT;
"+"  return ADDOP; 
"-"  return MINOP; 
"*"  return MULOP;
"/"  return DIVOP;
div  return DIV;
mod  return MOD;
abs  return ABS;
pow  return POW;
sqrt return SQRT;
exp  return EXP;
log  return LOG;
ln   return LN;
{integer}  yylval.intval = atoi( yytext ); return INTEGER;
{real}   return REAL;
{char}   return CHAR;
{string} return STRING;
{boolean}   return BOOLEAN;
{type}  return TYPE;
var     return VAR;
if      return IF;
then    return THEN;
elif    return ELIF;
else    return ELSE;
endif   return ENDIF;
while   return WHILE;
do      return DO;
endwhile    return ENDWHILE;
beginstmt   return BEGSTMT;
endstmt     return ENDSTMT;
":="        return ASSIGNMENT;
Function return FCT;
return return RETURN;
"public"|"private"|"protected"|"final" return MODIFIER;
Class return CLASS;
endClass return ENDCLASS;
new return NEWINSTCLASS;
write return WRITE;     
{identifier}    yylval.id = (char *) strdup(yytext); return(ID); 
{WS}						;
{line}						++cnt_line;
.							{return(yytext[0]);}

%%

// Supplementary C functions
int yywrap(void) {return 1;}