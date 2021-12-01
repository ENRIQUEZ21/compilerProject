%{
    #include <stdio.h>
%}

%%

[-+*/] printf("ARITHMETIC_OPERATOR");
[0-9] printf("DIGIT");
[a-zA-Z] printf("LETTER");
. printf("Unexpected character");

%%

int yywrap(void) {return 1;}
int main() {
    yyin = fopen("input.txt", "r");
    yyout = fopen("output.txt", "w");

    fprintf(yyout, "These are the tokens");
}

