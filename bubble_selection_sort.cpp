#include <iostream>
#include <vector>
using namespace std;

// Function for Bubble Sort
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Function for Selection Sort
void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        swap(arr[i], arr[minIdx]);
    }
}

// Function to display the array
void displayArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    int choice;
    int n;
    vector<int> arr;

    // Asking user for sorting choice
    cout << "Choose a sorting algorithm:" << endl;
    cout << "1. Bubble Sort" << endl;
    cout << "2. Selection Sort" << endl;
    cout << "Enter your choice (1 or 2): ";
    cin >> choice;

    // Input the array size
    cout << "Enter the number of elements: ";
    cin >> n;

    // Input the array elements
    arr.resize(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Perform sorting based on user choice
    if (choice == 1) {
        cout << "Performing Bubble Sort..." << endl;
        bubbleSort(arr);
    } else if (choice == 2) {
        cout << "Performing Selection Sort..." << endl;
        selectionSort(arr);
    } else {
        cout << "Invalid choice! Exiting..." << endl;
        return 1;
    }

    // Display the sorted array
    cout << "Sorted array: ";
    displayArray(arr);

    return 0;
}
