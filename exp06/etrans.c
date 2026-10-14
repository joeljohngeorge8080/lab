#include<stdio.h>

#define MAX 20

int main()
{
    int a,n,m,i,j,k,u,v,e[MAX+1][MAX+1]={0};
    char c;

    printf("Enter number of alphabets: ");
    if(scanf("%d",&a)!=1) return 1;
    printf("Enter alphabets (use e for epsilon):\n");
    for(i=0;i<a;i++) if(scanf(" %c",&c)!=1) return 1;

    printf("Enter number of states: ");
    if(scanf("%d",&n)!=1 || n<1 || n>MAX) { printf("States must be 1..%d\n",MAX); return 1; }
    printf("Enter number of transitions: ");
    if(scanf("%d",&m)!=1) return 1;
    printf("Enter transitions (source symbol destination):\n");
    for(i=0;i<m;i++)
    {
        if(scanf(" %d %c %d",&u,&c,&v)!=3 || u<1 || u>n || v<1 || v>n) { printf("Invalid transition\n"); return 1; }
        if(c=='e') e[u][v]=1;
    }

    for(i=1;i<=n;i++) e[i][i]=1;                      /* each state is in its own closure */
    for(k=1;k<=n;k++)                                  /* Warshall: all chains of epsilon moves */
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                if(e[i][k] && e[k][j]) e[i][j]=1;

    for(i=1;i<=n;i++)
    {
        printf("E-closure(q%d) = {",i);
        for(j=1;j<=n;j++) if(e[i][j]) printf("q%d ",j);
        printf("}\n");
    }
    return 0;
}
