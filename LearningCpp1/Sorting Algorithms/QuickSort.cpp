#include <iostream>
#include <vector>

using namespace std;

// Partition function to place the pivot element at its correct position
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // Choose the last element as the pivot
    int i = low - 1; // Index of the smaller element

    for (int j = low; j <= high - 1; j++) {
        // If the current element is smaller than or equal to the pivot
        if (arr[j] <= pivot) {
            i++;
           swap(arr[i], arr[j]);
        }
    }

    // Swap the pivot element with the element at (i + 1)
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Recursive function to implement quick sort
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        // Partition the array into two halves and get the index of the pivot element
        int pivotIndex = partition(arr, low, high);

        // Recursively sort the sub-arrays before and after the pivot element
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

int main() {
    vector<int> arr = {10, 7, 8, 9, 1, 5};

    cout << "Original array: ";
    for (int num : arr) {
        cout << num << " ";
    }

    quickSort(arr, 0, arr.size() - 1);

    cout << "\nSorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }

    return 0;
}
