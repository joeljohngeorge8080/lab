%{
#include<stdio.h>
int yylex();
int yyerror(char *);
%}
%token DIGIT ALPHA
%%
var : ALPHA
    | var ALPHA
    | var DIGIT
    ;
%%
int main()
{
    printf("Enter identifier: ");
    if(yyparse()==0) printf("Valid Identifier\n");
    return 0;
}
int yyerror(char *s)
{
    printf("Invalid Identifier\n");
    return 0;
}
