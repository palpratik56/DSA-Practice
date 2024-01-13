#include <stdio.h>

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // Create temporary arrays
    int L[n1], R[n2];

    // Copy data to temporary arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Merge the temporary arrays back into arr[l..r]
    i = 0,j=0,k=l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) 
            arr[k] = L[i++];
        else 
            arr[k] = R[j++];
        k++;
    }
    while (i < n1) 
        arr[k++] = L[i++];
    while (j < n2) 
        arr[k++] = R[j++];
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        // Same as (l+r)/2, but avoids overflow for large l and r
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main() {
    int arr[] = {11,13,5,6,18,33,0,7,-1};
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("Given array is \n");
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    mergeSort(arr, 0, size - 1);
    printf("\nSorted array is \n");
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);

    return 0;
}
