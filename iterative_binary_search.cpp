#include <iostream>
using namespace std;

int binarySearchIterative(int arr[], int n, int key) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;    // safe mid calculation

        if (arr[mid] == key)                 // key found
            return mid;
        else if (arr[mid] < key)             // key is in right half
            low = mid + 1;
        else                                 // key is in left half
            high = mid - 1;
    }

    return -1;                               // key not found
}

int main() {
    // IMPORTANT: Array must be sorted!
    int arr[] = {3, 12, 21, 45, 56, 67, 89};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 45;

    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    int result = binarySearchIterative(arr, n, key);
    if (result != -1)
        cout << "Found " << key << " at index " << result << endl;
    else
        cout << key << " not found" << endl;

    return 0;
}
