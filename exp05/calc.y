%{
#include<stdio.h>
int yylex();
int yyerror(char *);
%}
%token NUMBER
%left '+' '-'
%left '*' '/' '%'
%%
input : E '\n' {printf("Result: %d\n",$1);} ;
E : E '+' E {$$=$1+$3;}
  | E '-' E {$$=$1-$3;}
  | E '*' E {$$=$1*$3;}
  | E '/' E {$$=$1/$3;}
  | E '%' E {$$=$1%$3;}
  | '(' E ')' {$$=$2;}
  | NUMBER
  ;
%%
int main() { printf("Enter expression: "); if(yyparse()==0) printf("Valid Expression\n"); return 0; }
int yyerror(char *s) { printf("Invalid Expression\n"); return 0; }
