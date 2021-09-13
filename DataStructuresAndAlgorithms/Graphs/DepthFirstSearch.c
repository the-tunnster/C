#include <stdio.h>
#include <stdlib.h>

struct list{
    int v;
    struct list *next;
} **edge; 

void init(int N){
    for(int i=0;i<N;i++)
        edge[i]=NULL;
}

void addEdge(int u, int v){
    struct list *tmp=(struct list*)malloc(sizeof(struct list));
    tmp->v=v;
    tmp->next=NULL;
    if(edge[u]==NULL)
        edge[u]=tmp;
    else{
        tmp->next=edge[u];
        edge[u]=tmp;
    }
}

void dfs(int i, int vis[]){
    vis[i]=1;
    struct list *tmp=edge[i];
    while (tmp!=NULL){
        if(!vis[tmp->v])
            dfs(tmp->v,vis);
        tmp=tmp->next;
    }
}

int main(){
    int N=0,M,u,v;
    printf("Enter the number of vertices and the number of edge\n");
    scanf("%d%d",&N,&M);
    edge=(struct list**)malloc(N*sizeof(struct list*));
    init(N);

    for(int i=0;i<M;i++){
        printf("Enter an edge\n");
        scanf("%d%d",&u,&v);
        u--;
        v--;
        addEdge(u,v);
        addEdge(v,u);
    }

    int vis[N];
    for(int i=0;i<N;i++)
        vis[i]=0;

    dfs(0,vis);
    int flag=1;
    for(int i=0;i<N;i++)
        flag&=vis[i];

    printf("\nThe graph is: ");
    printf(flag?"Connected\n":"Not connected\n");
    return 0;
}
