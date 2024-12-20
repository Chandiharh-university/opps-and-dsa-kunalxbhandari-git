#include <iostream>
using namespace std;

// Function to perform Insertion Sort
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Function to merge two arrays for Merge Sort
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int i = 0; i < n2; i++) R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

// Function to perform Merge Sort
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// Function to perform Bubble Sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Function to perform Selection Sort
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

// Function to display the array
void displayArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int choice;
    cout << "Choose a sorting technique:\n";
    cout << "1. Insertion Sort\n";
    cout << "2. Merge Sort\n";
    cin >> choice;

    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    if (choice == 1) {
        insertionSort(arr, n);
        cout << "Sorted array using Insertion Sort:\n";
        displayArray(arr, n);
    } else if (choice == 2) {
        mergeSort(arr, 0, n - 1);
        cout << "Sorted array using Merge Sort:\n";
        displayArray(arr, n);
    } else {
        cout << "Invalid choice.\n";
        return 1;
    }

    cout << "\nNow, choose another sorting technique for the same array:\n";
    cout << "3. Bubble Sort\n";
    cout << "4. Selection Sort\n";
    cin >> choice;

    if (choice == 3) {
        bubbleSort(arr, n);
        cout << "Sorted array using Bubble Sort:\n";
        displayArray(arr, n);
    } else if (choice == 4) {
        selectionSort(arr, n);
        cout << "Sorted array using Selection Sort:\n";
        displayArray(arr, n);
    } else {
        cout << "Invalid choice.\n";
    }

    return 0;
}
