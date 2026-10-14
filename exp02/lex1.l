%{
#include<stdio.h>
%}
letter [a-zA-Z]
digit [0-9]
%%
#.*                {printf("%s : Preprocessor\n",yytext);}
{digit}+           {printf("%s : Number\n",yytext);}
{digit}+"."{digit}+ {printf("%s : Float\n",yytext);}
"int"|"char"|"void"|"if"|"else"|"while"|"return" {printf("%s : Keyword\n",yytext);}
{letter}({letter}|{digit})* {printf("%s : Identifier\n",yytext);}
"+"|"-"|"*"|"/"|"="|"<"|">"|"%" {printf("%s : Operator\n",yytext);}
[{}()\[\];,.#]     {printf("%s : Special symbol\n",yytext);}
[ \t\n]+           ;
.                  ;
%%
int main()
{
    yylex();
    return 0;
}
int yywrap()
{
    return 1;
}
