#include<stdio.h>
#define max 100

int total_nodes;

void print(int subset[] , int subsetSize){
    for(int i =0 ; i<subsetSize ; i++){
        printf("%d \t" , subset[i]);
    }
    printf("\n");
}

void sumOfSubsets(int set[] , int subset[] , int n , int subsetSize , 
                 int nodeSum , int targetSum){


        total_nodes++;
        if(nodeSum == targetSum ){
            print(subset , subsetSize);
        }

        //no elements left:
        if(n==0 || nodeSum > targetSum){
            return;
        }

        //include current element (X1 = 1)
        subset[subsetSize] = set[0];
        sumOfSubsets(set+1 , subset , n-1 , subsetSize+1 , nodeSum+set[0] , targetSum);
        //excluding current element (X1 = 0)
        sumOfSubsets(set+1 , subset , n-1 , subsetSize , nodeSum , targetSum);
}   

int main(){
    int set[] = {10, 7, 5, 18, 12, 20, 15};
    int n = sizeof(set) / sizeof(set[0]);
    int targetSum = 35;
    int subset[max];

    total_nodes = 0;

    printf("\nSubsets with the given sum are:\n");
    sumOfSubsets(set, subset, n, 0, 0, targetSum);

    printf("\nTotal nodes generated: %d\n", total_nodes);

    return 0;
}