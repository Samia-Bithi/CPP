#include <iostream>
using namespace std;

int binarySearchRecursive(int arr[], int low, int high, int key) {
    if (low > high)
        return -1;

    int mid = low + (high - low) / 2;

    if (arr[mid] == key)
        return mid;
    else if (arr[mid] < key)
        return binarySearchRecursive(arr, mid + 1, high, key);
    else
        return binarySearchRecursive(arr, low, mid - 1, key);
}

int main() {
    int arr[] = {3, 12, 21, 45, 56, 67, 89};
    int n = 7;
    int key = 21;

    int result = binarySearchRecursive(arr, 0, n - 1, key);
    if (result != -1)
        cout << "Found " << key << " at index " << result << endl;
    else
        cout << key << " not found" << endl;

    return 0;
}
