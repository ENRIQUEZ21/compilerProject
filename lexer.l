%{
    #include "scanner.h"
%}



WS     [ \t]+
digit  [0-9]
letter [a-zA-Z]
alphanum {letter}|{digit}|_
identifier {letter}{alphanum}*
integer {digit}{digit}*
real {digit}{digit}*.{digit}*
char '{alphanum}*'
string \"{alphanum}*\"
boolean true|false
literal {integer}|{char}|{string}|{boolean}|{real}

comment  \{({alphanum}|{WS}|{arithmetic_operator}|{boolean_operator})*\}


mathematical_function exp|log|ln|abs|pow|sqrt


type integer|char|string|boolean|real
declaration var{WS}{WS}*{identifier}(,{WS}*{identifier})*{WS}*:{WS}*{type}

arithmetic_operator [-+*/]|div|mod
boolean_operator ==|<=|>=|<|>|<>|and|or|not
call_function ({mathematical_function}|{identifier}){WS}{WS}*({identifier}|{literal})({WS}*,{WS}*({identifier}|{literal}))*{WS}*:{WS}*func
arithmetical_expression ({identifier}|{literal}|{call_function}){WS}*{arithmetic_operator}{WS}*({identifier}|{literal}|{call_function})
boolean_expression ({identifier}|{literal}|{call_function}){WS}*{boolean_operator}{WS}*({identifier}|{literal}|{call_function})
expression {boolean_expression}|{arithmetical_expression}
assignment :=
statement {identifier}{WS}*{assignment}{WS}*({expression}|{literal}|{identifier}|{call_function})

write write{WS}{WS}*({identifier}|{literal})


group_statements begin{WS}{WS}*(({statement}|{comment}|{declaration}|{write}){WS}{WS}*)*end


if_statement if{WS}{WS}*{boolean_expression}{WS}{WS}*then{WS}{WS}*({group_statements}{WS}{WS}*)
elif_statement elif{WS}{WS}*{boolean_expression}{WS}{WS}*then{WS}{WS}*({group_statements}{WS}{WS}*)
else_statement else{WS}{WS}*({group_statements}{WS}{WS}*)
simple_if_statement {if_statement}
if_else_statement {if_statement}{elif_statement}*{else_statement}
conditional_statement {simple_if_statement}|{if_else_statement}

while_statement while{WS}{WS}*{boolean_expression}{WS}{WS}*
do_statement do{WS}{WS}*({group_statements}{WS}{WS}*)
loop_statement {while_statement}{do_statement}

function_with_arg function{WS}{WS}*{identifier}{WS}*({WS}*{identifier}({WS}*,{WS}*{identifier}{WS}*)*){WS}*:{WS}*{type}{WS}{WS}*({group_statements}{WS}{WS}*)return{WS}{WS}*({identifier}|{literal})
function_without_args function{WS}{WS}*{identifier}{WS}*:{WS}*{type}{WS}{WS}*({group_statements}{WS}{WS}*)return{WS}{WS}*({identifier}|{literal})

function {function_with_arg}|{function_without_args}

modifier public|private|protected|final
class {modifier}{WS}{WS}*class{WS}{WS}*{identifier}{WS}{WS}*({group_statements}{WS}{WS}*)



%%



 /* end prgm to add - real to add - change assignment - change print to read - remove read */
{WS} ;
{comment} ;
{digit} printf("DIGIT");
startprgm printf("START_PROGRAM");
{write} printf("WRITE_STATEMENT"); 

endprgm printf("END_PROGRAM");

{statement} printf("STATEMENT");
{group_statements} printf("GROUP OF STATEMENTS");
{conditional_statement} printf("conditional_statement");
{loop_statement} printf("loop_statement");
{function} printf("FUNCTION");
{class} printf("CLASS");
. printf("Unexpected character");

%%

int yywrap(void) {return 1;}

int main() {
    printf("Enter a string: ");
    yylex();
    

    return 0;
}


