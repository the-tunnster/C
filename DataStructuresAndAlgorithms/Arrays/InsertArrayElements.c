#include <stdio.h>
#include <stdlib.h>

void AcceptArray(int arr[], int size){
    printf("Enter the elements.\n");
    for(int i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
}

int* InsertElement(int* arr, int size, int location, int value){
    int * Temp=(int *)malloc(sizeof(int)*(size+1));
    for(int i=0;i<size+1;i++){
        if(i<location){
            Temp[i]=arr[i];
        }
        if(i==location){
            Temp[i]=value;
        }
        if(i>location){
            Temp[i]=arr[i-1];
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
    printf("Which element do you wish to insert?\n");
    int value;
    scanf("%d",&value);
    printf("Where do you wish to insert it?\n");
    int location;
    scanf("%d",&location);
    arr=InsertElement(arr, size, location, value);
    size++;
    printf("The new array is :\n");
    DisplayArray(arr,size);
}