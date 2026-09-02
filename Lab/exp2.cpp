// EXPERIMENT 2 — QUEUE USING ARRAY + CIRCULAR QUEUE

#include <iostream>
using namespace std;

// Normal Queue using Array
class Queue
{
    int *arr;
    int front;
    int rear;
    int size;

public:
    Queue(int n)
    {
        size = n;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    void enqueue(int value)
    {
        if (rear == size - 1)
        {
            cout << "Queue Overflow\n";
            return;
        }

        if (front == -1)
            front = 0;

        arr[++rear] = value;

        cout << value << " inserted into queue\n";
    }

    void dequeue()
    {
        if (front == -1 || front > rear)
        {
            cout << "Queue Underflow\n";
            return;
        }

        cout << arr[front] << " deleted from queue\n";
        front++;

        if (front > rear)
        {
            front = -1;
            rear = -1;
        }
    }

    void display()
    {
        if (front == -1)
        {
            cout << "Queue is empty\n";
            return;
        }

        cout << "Queue: ";

        for (int i = front; i <= rear; i++)
            cout << arr[i] << " ";

        cout << endl;
    }

    ~Queue()
    {
        delete[] arr;
    }
};


// Circular Queue
class CircularQueue
{
    int *arr;
    int front;
    int rear;
    int size;

public:
    CircularQueue(int n)
    {
        size = n;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    bool isFull()
    {
        return ((rear + 1) % size == front);
    }

    bool isEmpty()
    {
        return front == -1;
    }

    void enqueue(int value)
    {
        if (isFull())
        {
            cout << "Circular Queue Overflow\n";
            return;
        }

        if (isEmpty())
        {
            front = rear = 0;
        }
        else
        {
            rear = (rear + 1) % size;
        }

        arr[rear] = value;

        cout << value << " inserted into circular queue\n";
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Circular Queue Underflow\n";
            return;
        }

        cout << arr[front] << " deleted from circular queue\n";

        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % size;
        }
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Circular Queue is empty\n";
            return;
        }

        cout << "Circular Queue: ";

        int i = front;

        while (true)
        {
            cout << arr[i] << " ";

            if (i == rear)
                break;

            i = (i + 1) % size;
        }

        cout << endl;
    }

    ~CircularQueue()
    {
        delete[] arr;
    }
};


int main()
{
    int n;

    cout << "Enter queue size: ";
    cin >> n;

    Queue q(n);
    CircularQueue cq(n);

    int choice, value;

    do
    {
        cout << "\n========== QUEUE MENU ==========\n";
        cout << "1. Enqueue (Normal Queue)\n";
        cout << "2. Dequeue (Normal Queue)\n";
        cout << "3. Display Normal Queue\n";
        cout << "4. Enqueue (Circular Queue)\n";
        cout << "5. Dequeue (Circular Queue)\n";
        cout << "6. Display Circular Queue\n";
        cout << "7. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                q.enqueue(value);
                break;

            case 2:
                q.dequeue();
                break;

            case 3:
                q.display();
                break;

            case 4:
                cout << "Enter value: ";
                cin >> value;
                cq.enqueue(value);
                break;

            case 5:
                cq.dequeue();
                break;

            case 6:
                cq.display();
                break;

            case 7:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice\n";
        }

    } while (choice != 7);

    return 0;
}