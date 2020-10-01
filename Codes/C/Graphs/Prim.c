#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct list
{
    int v,weight;
    struct list *next;
} **edge=NULL;
void init(int N){
    for(int i=0;i<N;i++)
        edge[i]=NULL;
}
void addEdge(int u, int v, int weight)
{
    struct list *tmp=(struct list*)malloc(sizeof(struct list));
    tmp->v=v;
    tmp->weight=weight;
    tmp->next=NULL;

    if(edge[u]==NULL)
        edge[u]=tmp;
    else
    {
        tmp->next=edge[u];
        edge[u]=tmp;
    }
}
int next(int selected[],int N)
{
    int min=INT_MAX,u=-1,v=-1;
    for(int i=0;i<N;i++)
    {
        if(selected[i])
        {
            struct list *tmp=edge[i];
            while (tmp!=NULL)
            {
                if(!selected[tmp->v]&&tmp->weight<min)
                {
                    min=tmp->weight;
                    u=i;
                    v=tmp->v;
                }
                tmp=tmp->next;
            }
        }
    }
    selected[v]=1;
    printf("%d - %d\n",(u+1),(v+1));
    return min;
}
void MST(int N)
{
    int selected[N],ans=0;
    for(int i=0;i<N;i++) selected[i]=0;

    selected[0]=1;
    for(int i=0;i<N-1;i++)
        ans+=next(selected,N);

    printf("\nThe weight is: %d\n\n",ans);
}
int main() //main method
{
    int N=0,M,u,v,weight;

    printf("Enter the number of vertices and the number of edge\n");
    scanf("%d%d",&N,&M);

    edge=(struct list**)malloc(N*sizeof(struct list*));
    init(N);

    for(int i=0;i<M;i++)
    {
        printf("Enter an edge\n");
        scanf("%d%d%d",&u,&v,&weight);
        u--;v--;

        addEdge(u,v,weight);
        addEdge(v,u,weight);
    }

    printf("The spanning tree is:\n");
    MST(N);

    return 0;
}
