#include <iostream>

using namespace std;


#define SIZE 5

int stack [SIZE];

int top = -1;

void push (int value)
{
    if(top == SIZE-1)
    {
        cout << "Stack overflow\n";
        return;
    }
    stack[++top] = value;

}

void pop()
{
    if( top == -1 )
    {
         cout << "Stack underflow \n";
        return;

    }
    cout << "Popped "<< stack[top--] << endl;

}


void peek()
{

    if (top == -1)
        cout << "Empty stack" <<endl;
    else
        cout << "Top: " << stack[top] << endl;

}

void display()
{
    for(int i = top; i>=0; i--)
        cout << stack[i] << " " << endl;
}

int main()
{
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);

    display();
    peek();
    pop();
    display();


    return 0;
}
