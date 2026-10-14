#include<stdio.h>

#define MAX 256

char s[MAX];
int i=0,err=0;

void E();

void F()
{
    if(s[i]=='a') i++;
    else if(s[i]=='(')
    {
        i++;
        E();
        if(s[i]==')') i++;
        else err=1;
    }
    else err=1;
}

void T()
{
    F();
    while(s[i]=='*') { i++; F(); }
}

void E()
{
    T();
    while(s[i]=='+') { i++; T(); }
}

int main()
{
    int c,n=0;

    printf("Enter expression: ");
    while((c=getchar())!='\n' && c!=EOF)
    {
        if(c==' ' || c=='\t') continue;
        if(n==MAX-1) { printf("Input too long\n"); return 1; }
        s[n++]=c;
    }

    E();
    puts(!err && i==n ? "Accepted" : "Rejected");
    return 0;
}
