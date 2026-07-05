#include <iostream>
using namespace std;

void quick(int A[], int n, int beg, int end, int &Loc) {
    int left = beg;
    int right = end;
    int loc = beg;

    while (true) {
        // scan right to left
        while (A[loc] <= A[right] && loc != right) {
            right = right - 1;
        }
        if (loc == right) {
            Loc = loc;
            return;
        }
        if (A[loc] > A[right]) {
            int temp = A[loc];
            A[loc] = A[right];
            A[right] = temp;
            loc = right;
        }

        // scan left to right
        while (A[left] <= A[loc] && left != loc) {
            left = left + 1;
        }
        if (loc == left) {
            Loc = loc;
            return;
        }
        if (A[left] > A[loc]) {
            int temp = A[loc];
            A[loc] = A[left];
            A[left] = temp;
            loc = left;
        }
    }
}
void quicksort_stack(int A[],int n){
    int top=0;
    int max_stack=n+5;
    int lower[max_stack];
    int upper[max_stack];
    if(n>=2){
        top=top+1;
        lower[top]=0;
        upper[top]=n-1;
    }
    while(top!=0){
        int beg=lower[top];
        int end= upper[top];
        top=top-1;
        int Loc;
        quick(A,n,beg,end,Loc);
        if(beg<Loc-1){
            top=top+1;
            lower[top]=beg;
            upper[top]=Loc-1;
        }
        if(Loc+1<end){
            top=top+1;
            lower[top]=Loc+1;
            upper[top]=end;
        }
    }
}

int main(){
    int A[]={64,34,24,12,22,15,90};
    int n=sizeof(A)/sizeof(A[0]);

    quicksort_stack(A,n);
    cout<<"sorted list: ";
    for(int i=0;i<n;i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
}




