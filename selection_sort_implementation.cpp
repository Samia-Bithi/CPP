#include<iostream>
using namespace std;


void selectionsort(int arr[],int n){
    for (int i=0;i<n-1;i++){
        int minindex=i;
        for(int j=i+1;j<n;j++){
            if (arr[j]<arr[minindex])
                minindex=j;
        } int temp=arr[i];
        arr[i]=arr[minindex];
        arr[minindex]=temp;
    }
}


 void display(int arr[],int n)
{   for (int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}


 int main(){
    int arr[]={64,34,24,12,22,15,90};
    int n=sizeof(arr)/sizeof(arr[0]);
    selectionsort(arr,n);
    cout<<"sorted array: ";
    display(arr,n);
    return 0;
}