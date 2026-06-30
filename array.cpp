#include <iostream>

using namespace std;

int main()
{
    int arr[20] = {10, 20, 30, 40, 50};
    int n = 5;

    // Insertion
    int pos = 2;
    int value = 25;

    for (int i = n; i>pos; i--)
        arr[i] = arr[i-1];
    arr[pos] = value;
    n++;

    //Traverse
    cout << "Array: ";
    for (int i = 0; i<n; i++)
        cout << arr[i] << " ";
    cout << endl;

    // Deletion
    int pos1 = 3;
    for(int i = pos1; i<n-1; i++)
        arr[i] = arr[i+1];

    n--;

      //Traverse
    cout << "Array after deletion: ";
    for (int i = 0; i<n; i++)
        cout << arr[i] << " ";
    cout << endl;

    // Search
    int key = 40;
    bool found = false;

    for(int i =0; i<n; i++)
    {
        if (arr[i] == key)
        {   cout << "\nFound at index " << i << endl;
            found = true;
            break;
        }
    }

    if(!found)
        cout << "\nNot Found" << endl;


    return 0;
}
