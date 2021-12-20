%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cnt_line = 0;

typedef enum{STARTPRGM=1, COMMA, DBPTS, OPENPAR, CLOSEPAR, OPENBRA, CLOSEBRA, OPENBRACK, CLOSEBRACK, 
SEMICOLON, DOT, INTEGER, REAL, CHAR, STRING, BOOLEAN, BOOLOP, ARITHMOP, TYPE, VAR,
IF, THEN, ELIF, ELSE, ENDIF, WHILE, DO, ENDWHILE, BEGSTMT, ENDSTMT, ASSIGNMENT, 
 MATHFCT, FCT, RETURN, MODIFIER, CLASS, ENDCLASS, COMMENT, WRITE, ID, WS, LINE} tok;

%}
delim [\t ]
WS {delim}+
line 			\n
letter [a-zA-Z]
digit  [0-9]
alphanum {letter}|{digit}|_
ponctuations ","|"."|":"|"("|")"|"{"|"}"|";"|"_"|"!"|"~"|"@"|"="|"&"|"["|"]"|"'"|"`"|"%"|"$"|"€"|"?"|"#"
identifier {letter}{alphanum}*
integer {digit}+
real {digit}+\.{digit}*
char '({alphanum}|{WS}|{ponctuations}|{arithmetic_operator}|{boolean_operator})*'
string \"({alphanum}|{WS}|{ponctuations}|{arithmetic_operator}|{boolean_operator})*\"
boolean true|false
comment  \{({alphanum}|{WS}|{arithmetic_operator}|{boolean_operator}|{ponctuations})*\}
mathematical_function exp|log|ln|abs|pow|sqrt
type integer|char|string|boolean|real
arithmetic_operator [-+*/]|div|mod
boolean_operator ==|<=|>=|<|>|<>|and|or|not
%%

start {printf("STARTPRGM\n");}
{comment} {printf("COMMENT\n");}
"," {printf("COMMA\n");}
":" {printf("DBPTS\n");}
"(" {printf("OPENPAR\n");}
")" {printf("CLOSEPAR\n");}
"{" {printf("OPENBRA\n");}
"}" {printf("CLOSEBRA\n");}
"[" {printf("OPENBRACK\n");}
"]" {printf("CLOSEBRACK\n");}
";" {printf("SEMICOLON\n");}
"." {printf("DOT");}
{boolean_operator} {printf("BOOLOP\n");}
{arithmetic_operator} {printf("ARITHMOP\n");}
{integer} {printf("INTEGER\n");}
{real} {printf("REAL\n");}
{char} {printf("CHAR\n");}
{string} {printf("STRING\n");}
{boolean} {printf("BOOLEAN\n");}
{type} {printf("TYPE\n");}
var {printf("VAR\n");}
if {printf("IF\n");}
then {printf("THEN\n");}
elif {printf("ELIF\n");}
else {printf("ELSE\n");}
endif {printf("ENDIF\n");}
while {printf("WHILE\n");}
do {printf("DO\n");}
endwhile {printf("ENDWHILE\n");}
begin {printf("BEGSTMT\n");}
end {printf("ENDSTMT\n");}
":=" {printf("ASSIGNMENT\n");}
{mathematical_function} {printf("MATHFCT\n");}
Function {printf("FCT\n");}
return {printf("RETURN\n");}
"public"|"private"|"protected"|"final" {printf("MODIFIER\n");}
Class {printf("CLASS\n");}
endClass {printf("ENDCLASS\n");}
write {printf("WRITE\n");} 
{identifier} {printf("ID\n");}
{WS}						{;}
{line}						{printf("%d ", ++cnt_line);}
.							{printf("Error : is not a valid token in line %d ", cnt_line); exit(3);}

%%

int yywrap(void) {return 1;}

int main() {
    printf("Enter a string: ");
    yylex();
    

    return 0;
}


