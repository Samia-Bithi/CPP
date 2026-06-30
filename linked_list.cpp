#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
    };

Node* head = NULL;

// Insertion
void insertB(int value)
{
    Node* temp = new Node();
    temp -> data = value;
    temp -> next = NULL;

    if (head == NULL)
    {
        head = temp;
        return;
    }

    Node* current = head;
    while(current -> next != NULL)
        current = current -> next;
    current -> next = temp;

}


// Delete first node
void deleteBeginning()
{
    if(head == NULL)
        return;

    Node* temp = head;
    head = head -> next;
    delete temp;
}


// Display
void display()
{
    Node* current = head;

    while (current != NULL)
    {
        cout << current -> data << " ";
        current = current -> next;
    }
    cout << endl;
}
int main()
{
    insertB(10);
    insertB(20);
    insertB(30);
    insertB(40);
    insertB(50);

    display();

    deleteBeginning();

    display();



    return 0;
}
