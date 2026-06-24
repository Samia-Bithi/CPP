#include <iostream>
using namespace std;

// Function returns index of key in arr[], or -1 if not found
int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) { // iterate from 0 to n-1
        if (arr[i] == key) { // compare each element
            return i; // found: return its index
        }
    }
    return -1; // not found
}

int main() {
    int arr[] = {45, 12, 67, 3, 89, 21, 56};
    int n = sizeof(arr) / sizeof(arr[0]); // calculate array size
    int key = 89;

    cout << "Array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    int result = linearSearch(arr, n, key);

    if (result != -1)
        cout << "Element " << key << " found at index " << result << endl;
    else
        cout << "Element " << key << " not found" << endl;

    return 0;
}
