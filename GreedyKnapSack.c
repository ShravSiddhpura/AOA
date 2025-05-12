#include<stdio.h>
#include<stdbool.h>



void swap( float a , float b){
    int temp = a;
    a = b;
    b = temp;
}

void sort(int n , float wt[] , float val[] ,float ratio[]){
    for(int i=0; i<n-1;i++){
        for(int j=i+1 ; j<n;j++){
            if(ratio[j] > ratio[i]){
                swap(ratio[i], ratio[j]);
                swap(wt[i], wt[j]);
                swap(val[i], val[j]);
            }
        }
    }
}

void knapsack(int n , float wt[] , float val[] , int capicity){
    float ratio[n];

    for(int i=0;i<n;i++){
        ratio[i] = val[i] / wt[i];
    }
    sort(n, wt, val, ratio);
    float totalValue = 0;
    for(int i=0;i<n;i++){
        if(wt[i] <=capicity){
            capicity -= wt[i];
            totalValue +=val[i];
        }
        else{
            totalValue += val[i] *(capicity/wt[i]);
            break;
        }
    }

    printf("Maximum value in Knapsack = %f\n", totalValue);
    printf("Remaining capacity = %d\n", capicity);
}

int main(){
    int n=3;
    float wt[] = {10, 20, 30};
    float val[] = {60, 100, 120};
    int capicity = 50;
    knapsack(n, wt, val, capicity);

}