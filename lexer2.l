%{
    
#include <string.h>
#include <stdlib.h>
#include "variables.h"
#include "yacc2.tab.h"
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
char '{alphanum}|{punctuations}'
string \"({alphanum}|{WS}|{punctuations})+\"
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
sqrt return SQRT;
exp  return EXP;
log  return LOG;
ln   return LN;
floor return FLOOR;
ceil  return CEIL;
cos  return COS;
sin  return SIN;
tan  return TAN;

"==" return EQ;
"<=" return LE;
">=" return GE;
"<"  return LT;
">"  return GT;
"<>" return NE;
and  return AND;
or   return OR;
not  return NOT;

{integer}  yylval.val.ival = atoi( yytext ); yylval.val.type = INT_TYPE; return INTEGER;
{real}  yylval.val.rval = atof( yytext ); yylval.val.type = REAL_TYPE; return REAL;
"true"   yylval.val.type = BOOL_TYPE; return TRUE;
"false"  yylval.val.type = BOOL_TYPE; return FALSE;
{char}   yylval.val.cval = (char *) strdup(yytext); yylval.val.type = CHAR_TYPE;  return CHAR;
{string} yylval.val.sval = (char *) strdup(yytext); yylval.val.type = STRING_TYPE; return STRING;
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

"DECLARATIONS"  return DECLARATIONS;
"STATEMENTS"    return STATEMENTS;
"FUNCTIONS"     return FUNCTIONS;

":="        return ASSIGNMENT;    
{identifier}    yylval.id = (char *) strdup(yytext); return(ID); 
{WS}						;
{line}						++cnt_line; 
.							{return(yytext[0]);}

%%

// Supplementary C functions
int yywrap(void) {return 1;}