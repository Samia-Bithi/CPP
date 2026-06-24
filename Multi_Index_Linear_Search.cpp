#include <iostream>
#include <vector>

using namespace std;

vector <int> linearSearchAll (int arr[], int n, int key){
    vector<int> positions;
    for (int i =0; i<n; i++){
        if ( arr[i] == key ){
            positions.push_back(i);
        }
    }
    return positions;
}

int main()
{
    int arr[] = {4,2,7,2,9,2,1};
    int n = 7;
    int key = 2;
    vector<int> result = linearSearchAll(arr, n, key);

    if (result.empty()){
        cout << "Element not found" << endl;
    }
    else{
        cout << "Element " << key << " found at indices:";
        for (int idx : result) cout << idx << " ";
        cout << endl;
    }

    return 0;

}
