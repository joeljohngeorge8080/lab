%{
#include<stdio.h>
int yylex();
int yyerror(char *);
%}
%token NUMBER ID
%left '+' '-'
%left '*' '/'
%%
exp : exp '+' exp
    | exp '-' exp
    | exp '*' exp
    | exp '/' exp
    | '(' exp ')'
    | NUMBER
    | ID
    ;
%%
int main()
{
    printf("Enter expression: ");
    if(yyparse()==0) printf("Valid Expression\n");
    return 0;
}
int yyerror(char *s)
{
    printf("Invalid Expression\n");
    return 0;
}
