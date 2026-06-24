#include <iostream>
using namespace std;

void sum(int a, int b, int c) {
    int d = a + b + c;
    cout << "Sum = " << d << endl;
}

int main() {
    int m, n, o;
    cout << "Enter any 3 integers: ";
    cin >> m >> n >> o;
    sum(m, n, o);
    return 0;
}
