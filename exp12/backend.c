#include<stdio.h>
#include<string.h>

int main()
{
    char code[30];
    const char *ops="+-*/", *names[]={"ADD","SUB","MUL","DIV"}, *p;
    int r=0;

    printf("Enter intermediate code (exit to stop):\n");
    while(scanf("%29s",code)==1 && strcmp(code,"exit")!=0)
    {
        p = strlen(code)>3 ? strchr(ops,code[3]) : NULL;
        if(p)
        {
            printf("MOV %c,R%d\n",code[2],r);
            printf("%s %c,R%d\n",names[p-ops],code[4],r);
            printf("MOV R%d,%c\n",r,code[0]);
        }
        r++;
    }
    return 0;
}
