#include <stdio.h>
#include <stdlib.h>

void AcceptArray(int arr[], int size){
    printf("Enter the elements.\n");
    for(int i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
}

int* BubbleSorter(int* arr, int size){
    for(int i=0;i<size;i++){
       for(int j=0;j<size-1;j++){
           if(arr[j]<arr[j+1]){
               int temp=arr[j];
               arr[j]=arr[j+1];
               arr[j+1]=temp;
           }
       }
    }
    return(arr);
}

void DisplayArray(int* arr, int size){
    for(int i=0;i<size;i++){
        printf("%d",arr[i]);
    }

}
void main(){
    printf("Enter the size of the array.\n");
    int size;
    scanf("%d",&size);
    int* arr=(int *)malloc(sizeof(int)*size);
    AcceptArray(arr, size);
    arr=BubbleSorter(arr, size);
    printf("The sorted array, in descending order, is :\n");
    DisplayArray(arr, size);
}