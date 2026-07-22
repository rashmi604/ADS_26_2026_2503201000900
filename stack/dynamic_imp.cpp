#include <iostream>
using namespace std;

struct Node
{
    int info;
    Node *next;
};

Node *top = NULL;

// Push Operation
void push(int x)
{
    Node *temp = new Node;

    temp->info = x;
    temp->next = top;
    top = temp;

    cout << x << " pushed into stack." << endl;
}

// Pop Operation
void pop()
{
    if (top == NULL)
    {
        cout << "Stack is Empty (Underflow)." << endl;
        return;
    }

    Node *temp = top;
    cout << "Deleted Element: " << top->info << endl;

    top = top->next;
    delete temp;
}

// Peek Operation
void peek()
{
    if (top == NULL)
    {
        cout << "Stack is Empty." << endl;
        return;
    }

    cout << "Top Element: " << top->info << endl;
}

// Traverse Operation
void traverse()
{
    if (top == NULL)
    {
        cout << "Stack is Empty." << endl;
        return;
    }

    Node *temp = top;

    cout << "Stack Elements: ";
    while (temp != NULL)
    {
        cout << temp->info << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    int choice, value;

    do
    {
        cout << "\n----- STACK USING LINKED LIST -----" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Traverse" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            push(value);
            break;

        case 2:
            pop();
            break;

        case 3:
            peek();
            break;

        case 4:
            traverse();
            break;

        case 5:
            cout << "Exiting..." << endl;
            break;

        default:
            cout << "Invalid Choice!" << endl;
        }

    } while (choice != 5);

    return 0;
}