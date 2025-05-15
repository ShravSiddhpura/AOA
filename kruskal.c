//define find func
//define union func
// now main function


#include <stdio.h>

#define V 5
#define INF 9999

int parent[V] ={0};

int find(int i){
    while(parent[i]){
        i = parent[i];
    }
    return i;
}

int unionS(int i, int j){
    if(i!=j){
        parent[j]=i;
        return 1;
    }
    
    return 0;
}

void kruskalMST(int cost[V][V]){
    int min,u,v,i,j,ne=1;
    printf("Edge : Weight\n");
    
    while(ne<V){
        min = INF;
        for( i=0;i<V;i++){
            for( j=0;j<V;j++){
                if(cost[i][j]<min){
                    min = cost[i][j];
                    u=i;
                    v=j;
                }
            }
        }
    int a = find(u);
    int b = find(v);
    
    if(unionS(a,b)){
        printf("%d - %d : %d\n", u, v, min);
        ne++;
    }
    }
    
    cost[u][v] = cost[v][u] = INF;
}

int main() {
    int cost[V][V] = {
        {INF, 2, INF, 6, INF},
        {2, INF, 3, 8, 5},
        {INF, 3, INF, INF, 7},
        {6, 8, INF, INF, 9},
        {INF, 5, 7, 9, INF}
    };

    kruskalMST(cost);
    return 0;
}


