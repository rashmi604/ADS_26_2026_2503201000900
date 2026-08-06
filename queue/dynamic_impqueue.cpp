#include <iostream>
using namespace std;

struct Node
{
    int info;
    Node *next;
};

Node *front = NULL;
Node *rear = NULL;

// Enqueue (Insertion)
void enqueue(int value)
{
    Node *newNode = new Node();

    newNode->info = value;
    newNode->next = NULL;

    if (front == NULL)
    {
        front = rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }

    cout << value << " inserted into queue." << endl;
}

// Dequeue (Deletion)
void dequeue()
{
    if (front == NULL)
    {
        cout << "Queue is empty." << endl;
    }
    else if (front == rear)
    {
        Node *temp = front;
        cout << temp->info << " deleted." << endl;
        front = rear = NULL;
        delete temp;
    }
    else
    {
        Node *temp = front;
        cout << temp->info << " deleted." << endl;
        front = front->next;
        delete temp;
    }
}

// Peek (Front Element)
void peek()
{
    if (front == NULL)
    {
        cout << "Queue is empty." << endl;
    }
    else
    {
        cout << "Front element = " << front->info << endl;
    }
}

// Display (Traverse)
void display()
{
    if (front == NULL)
    {
        cout << "Queue is empty." << endl;
        return;
    }

    Node *temp = front;

    cout << "Queue: ";

    while (temp != NULL)
    {
        cout << temp->info << " ";
        temp = temp->next;
    }

    cout << endl;
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

    dequeue();
    display();

    peek();

    return 0;
}