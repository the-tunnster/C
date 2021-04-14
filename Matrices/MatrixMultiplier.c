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


void Multiplier(int rows1, int rows2, int columns1, int columns2, int arr1[][columns1], int arr2[][columns2], int arr3[][columns2]){
    for(int i=0;i<rows1;i++){
        for(int j=0;j<columns2;j++){
            for(int k=0;k<columns1;k++){
                arr3[i][j]+=arr1[i][k]*arr2[k][j];
            }
        }
    }
}


void main(){
    printf("Enter the number of rows of the first matrix\n");
    int rows1;
    scanf("%d",&rows1);
    printf("Enter the number of columns of the first matrix\n");
    int columns1;
    scanf("%d",&columns1);
    int arr1[rows1][columns1];
    printf("Enter the number of rows of the second matrix\n");
    int rows2;
    scanf("%d",&rows2);
    printf("Enter the number of columns of the second matrix\n");
    int columns2;
    scanf("%d",&columns2);
    int arr2[rows2][columns2];
    if(columns1!=rows2){
        printf("Incompatible for multiplication...\n");
    }
    else {
        printf("Enter the elements of the first matrix.\n");
        Accept2DArray(rows1, columns1, arr1);
        printf("Enter the elements of the second matrix.\n");
        Accept2DArray(rows2, columns2, arr2);
        printf("The first matrix is :\n");
        Print2DArray(rows1, columns1, arr1);
        printf("The second matrix is :\n");
        Print2DArray(rows2, columns2, arr2);
        int arr3[rows1][columns2];
        for(int i=0;i<rows1;i++){
            for(int j=0;j<columns2;j++){
                arr3[i][j]=0;
            }
        }
        Multiplier(rows1, columns1, rows2, columns2, arr1, arr2, arr3);
        printf("The resultant matrix is :\n");
        Print2DArray(rows1, columns2, arr3);
    }
}