#include<stdio.h>
#include<time.h>

void swap(int a , int b){
    int temp = a;
    a = b;
    b = temp;
}

int part(int arr[] , int low , int high){
    int pivot = arr[high];
    int i=low-1;
    for(int j=low ; j<high ; j++){
        if(arr[j] < pivot){
            i++;
           // swap(arr[j] , arr[i]);
           int temp = arr[j];
           arr[j] = arr[i];
           arr[i] = temp;
        }
    }
    //swap(arr[i+1] , arr[high]);
    int temp = arr[i+1];
    arr[i+1] = arr[high];
    arr[high] = temp;
    return i+1;
}

void quickSort(int arr[] , int low  , int high){
    if(low<high){
        int p = part(arr,low,high);
        quickSort(arr , low ,p-1);
        quickSort(arr , p+1 , high);
    }
}

int main(){
    int arr[] = {5,2,7,2,9};
    int n = 5;
    clock_t start = clock();
    quickSort(arr , 0 , n-1);
    clock_t end = clock();
    printf("Sorted array: \n");
    for(int i=0 ; i<n ; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    printf("Time taken to sort the array: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
    return 0;
}