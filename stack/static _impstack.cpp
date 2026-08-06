#include <iostream>
using namespace std;

#define MAXSIZE 5

int st[MAXSIZE];
int top = -1;

// Check if stack is full
bool isOverflow()
{
    return top == MAXSIZE - 1;
}

// Check if stack is empty
bool isUnderflow()
{
    return top == -1;
}

// Push operation
void push(int x)
{
    if (isOverflow())
    {
        cout << "Stack is Full!" << endl;
        return;
    }

    top++;
    st[top] = x;
    cout << x << " pushed into stack." << endl;
}

// Pop operation
void pop()
{
    if (isUnderflow())
    {
        cout << "Stack is Empty!" << endl;
        return;
    }

    cout << st[top] << " is popped." << endl;
    top--;
}

// Peek operation
void peek()
{
    if (isUnderflow())
    {
        cout << "Stack is Empty!" << endl;
        return;
    }

    cout << "Top element is: " << st[top] << endl;
}

// Traverse operation
void traverse()
{
    if (isUnderflow())
    {
        cout << "Stack is Empty!" << endl;
        return;
    }

    cout << "Stack elements are: ";

    for (int i = top; i >= 0; i--)
    {
        cout << st[i] << " ";
    }

    cout << endl;
}

int main()
{
    int ch, value;

    do
    {
        cout << "\n----- STACK MENU -----" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Traverse" << endl;
        cout << "5. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            cout << "Enter the value: ";
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

    } while (ch != 5);

    return 0;
}