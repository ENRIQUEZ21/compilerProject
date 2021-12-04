%{
    #include <stdio.h>
%}

%%

[{] printf("BEGIN_COMMENT");
[}] printf("END_COMMENT");
start printf("START_PROGRAM"); 
[0-9][0-9]* printf("NUMBER");
'[a-zA-Z0-9_]*' printf("CHAR");
\"[a-zA-Z0-9_]*\" printf("STRING");
true|false printf("BOOLEAN");
function printf("FUNCTION");
:= printf("ASSIGNMENT");
if printf("IF_STATEMENT");
then printf("THEN_STATEMENT");
else printf("ELSE_STATEMENT");
while printf("WHILE_STATEMENT");
do printf("DO_STATEMENT");
read printf("READ_STATEMENT");
print printf("PRINT_STATEMENT");
begin printf("BEGIN_GROUP_STATEMENT");
end printf("END_GROUP_STATEMENT");
public|private|protected|final printf("MODIFIER");
class printf("CLASS");
var printf("VAR_DECLARATION");
integer|char|boolean|real|string printf("TYPE");
[a-zA-Z][a-zA-Z0-9_]* printf("IDENTIFIER");
==|<=|>=|<|>|<>|and|or|not printf("BOOLEAN_OPERATOR");
[-+*/] printf("ARITHMETIC_OPERATOR");
[0-9] printf("DIGIT");
[a-zA-Z] printf("LETTER");
. printf("Unexpected character");

%%

int yywrap(void) {return 1;}

int main() {
    printf("Enter a string: ");
    yylex();
    

    return 0;
}


