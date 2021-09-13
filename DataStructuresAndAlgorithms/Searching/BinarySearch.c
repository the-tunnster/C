#include <stdio.h>

void AcceptArray(int arr[], int size){
    printf("Enter the elements.\n");
    for(int i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
}
int BinarySearch(int arr[], int size, int value){
    int LowerBound=0;
    int UpperBound=size-1;
    int Middle=(LowerBound+UpperBound)/2;
    int location=-1;
    while(LowerBound<UpperBound){
        if(arr[Middle]<value){
            LowerBound=Middle+1;
        }
        else{
            if(arr[Middle]==value){
                location=Middle+1;
                break;
            }
            else{
                UpperBound=Middle;
            }
        }
        Middle=(LowerBound+UpperBound)/2;
    }
}
void main(){
    printf("Enter the size of the array.\n");
    int size;
    scanf("%d",&size);
    int arr[size];
    AcceptArray(arr, size);
    printf("Which element do you wish to locate?\n");
    int value;
    scanf("%d",&value);
    int location=BinarySearch(arr, size, value);
    if(location==-1){
        printf("Element doesn't exist in the array.\n");
    }
    else{
        printf("Element found at location %d.\n",location);
    }
}