#include <stdio.h>

void Accept2DArray(int rows, int columns, int arr[][columns]){
    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            scanf("%d",&arr[i][j]);
        }
    }
}

void Print2DArray(int rows, int columns, int arr[][columns]){
    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            printf("%d\t",arr[i][j]);
        }
        printf("\n");
    }
}


void Transpose(int rows, int columns, int arr[][columns]){
    int arr2[rows][columns];
    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            arr2[i][j]=arr[j][i];
        }
    }
    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            arr[i][j]=arr2[i][j];
        }
    }
}

void main(){
    printf("Enter the number of rows\n");
    int rows;
    scanf("%d",&rows);
    printf("Enter the number of columns\n");
    int columns;
    scanf("%d",&columns);
    int arr[rows][columns];
    printf("Enter the elements.\n");
    Accept2DArray(rows, columns, arr);
    Transpose(rows, columns, arr);
    Print2DArray(rows, columns, arr);
}