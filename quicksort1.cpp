#include <iostream>
using namespace std;

// Swap function
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Partition function
int partition(int arr[], int low, int high) {
    int pivot = arr[low];  // Set pivot
    int i = low + 1;       // Next location of pivot
    for (int j = low + 1; j <= high; j++) {
        if (arr[j] < pivot) {  
            swap(arr[i], arr[j]);  
            i++;  
        }
    }
    swap(arr[low], arr[i - 1]);  
    return (i - 1);  // Return the partitioning index for pivot
}

// Quicksort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int loc = partition(arr, low, high);

        // Sorting left and right side of pivot
        quickSort(arr, low, loc - 1);
        quickSort(arr, loc + 1, high);
    }
}

// Print the array function 
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Main function
int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n - 1);
    cout << "Sorted array: \n";
    printArray(arr, n);
    return 0;
}