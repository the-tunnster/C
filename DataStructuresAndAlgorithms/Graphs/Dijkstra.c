#include<stdio.h>
#include<string.h>
#include<math.h>
#define IN 9999

int N;
int dijkstra(int cost[][N], int source, int target);
char *strrev(char *str);

int main(){
    int cost[N][N], w, co;
    int source, target, x, y;
    printf("How many nodes do you wish to have?\n");
    scanf("%d", &N);
    for(int i=1;i< N;i++){
        for(int j=1;j< N;j++){
            cost[i][j] = IN;
        }
    }
    for(x=1;x< N;x++){
        for(y=x+1;y< N;y++){
            printf("Enter the weight of the path between nodes %d and %d: ",x,y);
            printf("If no direct path exists, please enter 9999.");
            scanf("%d",&w);
            if(w==9999){
                continue;
            }
            cost[x][y] = cost[y][x] = w;
        }
        printf("\n");
    }
    printf("\nEnter the source: ");
    scanf("%d", &source);
    printf("\nEnter the target: ");
    scanf("%d", &target);
    co = dijkstra(cost,source,target);
    printf("\nThe Shortest Path Distance: %d",co);
}

int dijkstra(int cost[][N],int source,int target){
    int dist[N], prev[N], selected[N], m, min, start, d, j;
    for(int i=0; i<N; i++){
        selected[i] = 0;
    }
    
    char path[N];
    for(int i=1;i< N;i++){
        dist[i] = IN;
        prev[i] = -1;
    }
    start = source;
    selected[start]=1;
    dist[start] = 0;
    while(selected[target] ==0){
        min = IN;
        m = 0;
        for(int i=1;i< N;i++){
            d = dist[start] +cost[start][i];
            if(d< dist[i]&&selected[i]==0){
                dist[i] = d;
                prev[i] = start;
            }
            if(min>dist[i] && selected[i]==0){
                min = dist[i];
                m = i;
            }
        }
        start = m;
        selected[start] = 1;
    }
    start = target;
    j = 0;
    while(start != -1){
        path[j++] = start+65;
        start = prev[start];
    }
    path[j]='\0';
    strrev(path);
    printf("%s", path);
    return dist[target];
}

char *strrev(char *str){
      char *p1, *p2;
      if (! str || ! *str)
            return str;
      for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2){
            *p1 ^= *p2;
            *p2 ^= *p1;
            *p1 ^= *p2;
      }
      return str;
}