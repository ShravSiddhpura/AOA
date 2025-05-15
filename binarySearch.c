#include<stdio.h>

int binarySearch(int arr[] , int n , int key){
    int high = n-1 , low = 0;
    int mid;
    while(low<high){
        mid = (low+high)/2;
        if(arr[mid] == key){
            return mid;
        }
        else if(mid > key){
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return -1;
}

int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    int key = 5;
    int result = binarySearch(arr , n , key);
    if(result == -1){
        printf("Element not found\n");
    }
    else{
        printf("Element found at index %d\n", result);
    }
    return 0;
}