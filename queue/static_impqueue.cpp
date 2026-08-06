#include <iostream>
using namespace std;

#define MAX_SIZE 5

class Queue
{
private:
    int q[MAX_SIZE];
    int front;
    int rear;

public:
    // Constructor
    Queue()
    {
        front = -1;
        rear = -1;
    }

    // Check whether queue is full
    bool isOverflow()
    {
        return rear == MAX_SIZE - 1;
    }

    // Check whether queue is empty
    bool isUnderflow()
    {
        return front == -1;
    }

    // Insert an element into the queue
    void enqueue(int x)
    {
        if (isOverflow())
        {
            cout << "Queue is full" << endl;
            return;
        }

        // Inserting the first element
        if (front == -1)
        {
            front = 0;
            rear = 0;
        }
        else
        {
            rear++;
        }

        q[rear] = x;

        cout << x << " inserted into the queue" << endl;
    }

    // Delete an element from the queue
    void dequeue()
    {
        if (isUnderflow())
        {
            cout << "Queue is empty" << endl;
            return;
        }

        cout << q[front] << " deleted from the queue" << endl;

        // Queue contains only one element
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front++;
        }
    }

    // Display the front element
    void peek()
    {
        if (isUnderflow())
        {
            cout << "Queue is empty" << endl;
            return;
        }

        cout << "Front element is: " << q[front] << endl;
    }

    // Display all elements of the queue
    void traverse()
    {
        if (isUnderflow())
        {
            cout << "Queue is empty" << endl;
            return;
        }

        cout << "Queue elements are: ";

        for (int i = front; i <= rear; i++)
        {
            cout << q[i] << " ";
        }

        cout << endl;
    }
};

int main()
{
    Queue queue;
    int choice;
    int value;

    do
    {
        cout << "\n----- QUEUE MENU -----" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Traverse" << endl;
        cout << "5. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter the element: ";
            cin >> value;
            queue.enqueue(value);
            break;

        case 2:
            queue.dequeue();
            break;

        case 3:
            queue.peek();
            break;

        case 4:
            queue.traverse();
            break;

        case 5:
            cout << "Program ended." << endl;
            break;

        default:
            cout << "Invalid choice. Please enter from 1 to 5." << endl;
        }

    } while (choice != 5);

    return 0;
}