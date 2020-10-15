#include <stdio.h>
#include <stdio.h>
void AcceptArray(int arr[], int size){
    printf("Enter the elements.\n");
    for(int i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
}
int LinearSearch(int arr[], int size, int value){
    int location=-1;
    for(int i=0;i<size;i++){
        if(arr[i]==value){
            location=i+1;
            break;
        }
    }
    return(location);
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
    int location=LinearSearch(arr, size, value);
    if(location==-1){
        printf("Element doesn't exist in the array.\n");
    }
    else{
        printf("Element found at location %d.\n",location);
    }
}