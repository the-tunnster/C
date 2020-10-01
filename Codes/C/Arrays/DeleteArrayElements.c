#include <stdio.h>
#include <stdlib.h>

void AcceptArray(int arr[], int size){
    printf("Enter the elements.\n");
    for(int i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
}

int* DeleteElement(int* arr, int size, int location){
    int * Temp=(int *)malloc(sizeof(int)*(size-1));
    for(int i=0;i<size;i++){
        if(i<location){
            Temp[i]=arr[i];
        }
        if(i==location){
            continue;
        }
        if(i>location){
            Temp[i-1]=arr[i];
        }
    }
    return(Temp);
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
    printf("Which location do you wish delete an element from?\n");
    int location;
    scanf("%d",&location);
    arr=DeleteElement(arr, size, location);
    size--;
    printf("The new array is :\n");
    DisplayArray(arr,size);
}