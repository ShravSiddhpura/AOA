#include<stdio.h>
#define INF 9999
#define V 5
#define E 8

void bellmanFord(int src){
    int dist[V];
    
    // Edge lists
    int u[E] = {0, 0, 1, 1, 1, 3, 3, 4};
    int v[E] = {1, 2, 2, 3, 4, 2, 1, 3};
    int w[E] = {-1, 4, 3, 2, 2, 5, 1, -3};

    for(int i=0;i<V;i++){
        dist[i] = INF;
    }
    dist[src] = 0;

    for(int i=0;i<V-1;i++){
        for(int j=0;j<E;j++){
            if(dist[u[j]]+w[j] < dist[v[j]]){
                dist[v[j]] = dist[u[j]] + w[j];
            }
        }
    }

    //For checking negative weight cycle
    for(int i=0;i<E;i++){
        if(dist[u[i]]+w[i] < dist[v[i]]){
            printf("Graph contains negative weight cycle\n");
            return;
        }
    }
    printf("Vertex\tDistance from Source\n");
    for(int i=0;i<V;i++){
        printf("%d\t%d\n", i, dist[i]);
    }
}

int main(){
    int src=0;
    bellmanFord(src);
    return 0;
}