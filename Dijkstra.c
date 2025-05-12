#include<stdio.h>

#define V 5
#define INF 9999

void Dj(int graph[V][V] , int src){
    int u,i,j,min;
    int visited[V] ;
    int dist[V];

    for(i=0;i<V;i++){
        visited[i] =0;
        dist[i] = INF;
    }

    dist[src] = 0;

    for(i=0;i<V-1;i++){
        min=INF;

        for(j=0;j<V;j++){
            if(!visited[j] && dist[j]<min){
                min = dist[j];
                u=j;
            }
        }
        visited[u] = 1;

        for(j=0;j<V;j++){
            if(!visited[j] && graph[u][j] && dist[u]+graph[u][j] < dist[j]){
                dist[j] = dist[u] + graph[u][j];
            }
        }
    }
    printf("Vertex\tDistance from Source\n");
    for(i=0;i<V;i++){
    printf("%d    \t       %d\n", i, dist[i]);
    }
}

int main() {
    int graph[V][V] = {
        {0, 10, 0, 30, 100},
        {10, 0, 50, 0, 0},
        {0, 50, 0, 20, 70},
        {30, 0, 20, 0, 60},
        {100, 0, 70, 60, 0}
    };

    Dj(graph , 0);
    return 0;
}