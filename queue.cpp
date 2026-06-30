#include <iostream>

using namespace std;

#define SIZE 5

int queue[SIZE];

int front = -1;
int rear = -1;

void enqueue(int value)
{
    if (rear == SIZE - 1)
    {
        cout << "Queue overflow\n";
        return;
    }

    if (front == -1)
        front = 0;

    queue[++rear] = value;
}

void dequeue()
{
    if (front == -1 || front > rear)
    {
        cout << "Queue underflow\n";
        return;
    }

    cout << "Dequeued " << queue[front++] << endl;

    if (front > rear)
    {
        front = rear = -1;
    }
}

void peek()
{
    if (front == -1)
        cout << "Empty queue" << endl;
    else
        cout << "Front: " << queue[front] << endl;
}

void display()
{
    if (front == -1)
    {
        cout << "Empty queue" << endl;
        return;
    }

    for (int i = front; i <= rear; i++)
        cout << queue[i] << " " << endl;
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);

    display();
    peek();
    dequeue();
    display();

    return 0;
}
