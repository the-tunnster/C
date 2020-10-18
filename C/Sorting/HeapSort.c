#include <stdio.h>
#include <stdlib.h>

void heapSort(int arr[], int n);
void printArray(int arr[], int size);
void heapify(int arr[], int n, int i);
void heapSort(int arr[], int n);
void swap(int* a, int* b);
void readArray(int n, int arr[]);


void main(){
    int size;
    printf("Enter size of the array \n");
    scanf("%d", &size);
    int arr[size];
    readArray(size, arr);
    heapSort(arr, size);
    printf("Sorted array: \n");
    printArray(arr, size);
}

void readArray(int n, int arr[]){
    printf("Enter elements of the Array \n");
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
}

void printArray(int arr[], int size) {
    for(int i=0; i < size; i++)
        printf("%d ", arr[i]);
}

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void heapify(int arr[], int n, int i)
{
    int largest = i; // Initialize largest as root
    int left = 2*i + 1; // left = 2*i + 1
    int right = 2*i + 2; // right = 2*i + 2

    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n){
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for (int i=n-1; i>=0; i--){
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}