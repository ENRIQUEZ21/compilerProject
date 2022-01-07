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
{comment}  return COMMENT;
beginstmt   return BEGSTMT;
endstmt     return ENDSTMT;
","  return COMMA; 
":"  return COLON;
";"  return SEMICOLON;
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
"==" return EQ;
"<=" return LE;
">=" return GE;
"<"  return LT;
">"  return GT;
"<>" return NE;
and  return AND;
or   return OR;
not  return NOT;
{integer}  yylval.intval = atoi( yytext ); return INTEGER;
{real}  yylval.doubleval = atof( yytext ); return REAL;
"true"   return TRUE;
"false"  return FALSE;
{char}   yylval.chstval = (char *) strdup(yytext);   return CHAR;
{string} yylval.chstval = (char *) strdup(yytext); return STRING;
"integer"   return INT_TYPE;
"real"      return REAL_TYPE;
"char"      return CHAR_TYPE;
"string"    return STRING_TYPE;
"boolean"   return BOOL_TYPE;
var     return VAR;
if      return IF;
then    return THEN;
elif    return ELIF;
else    return ELSE;
endif   return ENDIF;
while   return WHILE;
do      return DO;
endwhile    return ENDWHILE;
"Function" return FCT;
return return RETURN;
write return WRITE;
":="        return ASSIGNMENT;    
{identifier}    yylval.id = (char *) strdup(yytext); return(ID); 
{WS}						;
{line}						++cnt_line; 
.							{return(yytext[0]);}

%%

// Supplementary C functions
int yywrap(void) {return 1;}