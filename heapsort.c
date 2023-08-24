#include <stdio.h>
#include <stdlib.h>

void swap (int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void heapify (int arr[], int n, int i){
    int largest = i, left = 2*i+1, right = 2*i+2;

    if (left < n && arr[left] > arr[largest]){
        largest = left;
    }
    if (right < n && arr[right] > arr[largest]){
        largest = right;
    }
    if (largest != i){
        swap (&arr[i], &arr[largest]);
        heapify (arr, n, largest);
    }
}

void heapsort (int arr[], int n){
    for (int i=n/2-1; i>=0; i--){
        heapify (arr, n, i);
    }
    for (int i=n-1; i>=0; i--){
        swap (&arr[0], &arr[i]);
        heapify (arr, i, 0);
    }
}

int main (){
    int n;

    printf ("Enter number of elements: ");
    scanf ("%d", &n);
    int arr[n];

    printf ("Enter the elements: ");
    for (int i = 0; i < n; i++){
        scanf ("%d", &arr[i]);
    }
    heapsort (arr, n);
    printf ("Sorted elements: ");
    for (int i=0; i<n; i++){
        printf ("%d  ", arr[i]);
    }
    printf ("\n");
    return 0;
}