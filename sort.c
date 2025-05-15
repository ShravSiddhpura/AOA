// Online C compiler to run C program online
#include <stdio.h>
#include<stdlib.h>
#include<time.h>

void insetionSort(int arr[], int n){
    int i ,key,j;
    for(i=1;i<n;i++){
        key = arr[i];
        j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j--;
        }

        arr[j+1] = key;
    }
}

void selectionSort(int arr[], int n){
    int i,j,minIndex;
    for(i=0;i<n-1;i++){
        minIndex = i;
        for(j=i+1;j<n;j++){
            if(arr[j]<arr[minIndex]){
                minIndex = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

void printArray(int arr[], int n){
    int i;
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main(){
    int arr[ ] = {12, 11, 13, 5, 6};
    int n = sizeof(arr)/sizeof(arr[0]);

    clock_t strart = clock();
    selectionSor(arr , n);
    clock_t end = clock();
    printf("Sorted array: \n");
    printArray(arr , n);

    printf("Time taken to sort the array: %f seconds\n", (double)(end - strart) / CLOCKS_PER_SEC);
    return 0;
}