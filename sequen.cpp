#include <stdio.h>
#include <stdlib.h>

// Merge two sorted subarrays into one sorted array
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1; // Size of left subarray
    int n2 = right - mid;    // Size of right subarray

    // Allocate memory for temporary subarrays
    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    // Copy data to temp arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Merge the two subarrays back into the original array
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    // Copy any remaining elements from L[]
    while (i < n1)
        arr[k++] = L[i++];

    // Copy any remaining elements from R[]
    while (j < n2)
        arr[k++] = R[j++];

    // Free allocated memory
    free(L);
    free(R);
}

// Recursive function to perform Merge Sort
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2; // Find the middle point

        // Recursively sort first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

// Function to print array elements
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    // Initialize an array with unsorted values
    int arr[] = {64, 34, 25, 12, 22, 11, 90, 12, 34, 66, 88, 77, 44, 33, 55, 65};
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate the size of the array

    printf("Original array:\n");
    printArray(arr, n); // Print the original array

    // Sort the array using Merge Sort
    mergeSort(arr, 0, n - 1);

    printf("Sorted array:\n");
    printArray(arr, n); // Print the sorted array

    return 0;
}
