#include <stdio.h>
#include <stdlib.h>

void AcceptArray(int arr[], int size){
    printf("Enter the elements.\n");
    for(int i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
}

int* SelectionSorter(int* arr, int size){
    for(int i=0;i<size;i++){
       for(int j=i+1;j<size;j++){
           int min=arr[i];
           int location=i;
           if(arr[j]<min){
               min=arr[j];
               location=j;
           }
           int temp=arr[i];
           arr[i]=arr[location];
           arr[location]=temp;
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
    arr=SelectionSorter(arr, size);
    printf("The sorted array, in ascending order, is :\n");
    DisplayArray(arr, size);
}