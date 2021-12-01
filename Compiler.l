%{
    #include "stdio.h"
%}

%%

[-+*/] return ARITHMETIC_OPERATOR;
. printf("Unexpected character")

%%

yywrap() {}
int main() {
    yylex();
}

