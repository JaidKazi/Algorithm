#include <stdio.h>

// Function to perform binary search
int bin_search(int arr[], int target, int size) {
    int lower = 0;
    int upper = size - 1;
    int mid;

    while (lower <= upper) {
        mid = (lower + upper) / 2;

        if (arr[mid] == target) {
            return mid;
        } else if (target < arr[mid]) {
            upper = mid - 1;
        } else {
            lower = mid + 1;
        }
    }

    return -1;
}

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to sort the array in ascending order
void sort_array(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

int main() {
    int size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // Sort the array in ascending order
    sort_array(arr, size);

    printf("Sorted array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int target;

    printf("Enter the target value: ");
    scanf("%d", &target);

    int result = bin_search(arr, target, size);

    if (result == -1) {
        printf("No value found\n");
    } else {
        printf("Value found at index %d\n", result);
    }

    return 0;
}