//unsorted list
#include <iostream>
using namespace std;

class MaxPriorityQueue
{
    int *arr;
    int size;
    int capacity;

public:

    // Constructor
    MaxPriorityQueue(int cap = 10)
    {
        capacity = cap;
        size = 0;
        arr = new int[capacity];
    }

    // Insert element
    void enqueue(int x)
    {
        // Increase capacity if queue is full
        if (size == capacity)
        {
            capacity = capacity * 2;

            int *newArr = new int[capacity];

            for (int i = 0; i < size; i++)
            {
                newArr[i] = arr[i];
            }

            delete[] arr;
            arr = newArr;
        }

        // Unsorted insertion
        arr[size] = x;
        size++;

        cout << x << " inserted." << endl;
    }

    // Find and display maximum element
    void peek()
    {
        if (size == 0)
        {
            cout << "Priority Queue is empty." << endl;
            return;
        }

        int maxIndex = 0;

        for (int i = 1; i < size; i++)
        {
            if (arr[i] > arr[maxIndex])
            {
                maxIndex = i;
            }
        }

        cout << "Maximum element = " << arr[maxIndex] << endl;
    }

    // Delete maximum element
    void dequeue()
    {
        if (size == 0)
        {
            cout << "Priority Queue is empty." << endl;
            return;
        }

        int maxIndex = 0;

        // Find maximum element
        for (int i = 1; i < size; i++)
        {
            if (arr[i] > arr[maxIndex])
            {
                maxIndex = i;
            }
        }

        cout << "Deleted element = " << arr[maxIndex] << endl;

        // Shift elements to remove maximum element
        for (int i = maxIndex; i < size - 1; i++)
        {
            arr[i] = arr[i + 1];
        }

        size--;
    }

    // Display queue
    void display()
    {
        if (size == 0)
        {
            cout << "Priority Queue is empty." << endl;
            return;
        }

        cout << "Priority Queue: ";

        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }

        cout << endl;
    }

    // Destructor
    ~MaxPriorityQueue()
    {
        delete[] arr;
    }
};

int main()
{
    MaxPriorityQueue pq;

    int choice, x;

    while (true)
    {
        cout << "\n===== MAX PRIORITY QUEUE =====" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue (Delete Max)" << endl;
        cout << "3. Peek (Max)" << endl;
        cout << "4. Display" << endl;
        cout << "5. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter element: ";
                cin >> x;
                pq.enqueue(x);
                break;

            case 2:
                pq.dequeue();
                break;

            case 3:
                pq.peek();
                break;

            case 4:
                pq.display();
                break;

            case 5:
                cout << "Program ended." << endl;
                return 0;

            default:
                cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}

//sorted list
#include <iostream>
using namespace std;

class PriorityQueue
{
    int arr[100];
    int size;

public:

    PriorityQueue()
    {
        size = 0;
    }

    // Insert element in sorted order
    void enqueue(int x)
    {
        int i = size - 1;

        // Shift smaller elements to the right
        while (i >= 0 && arr[i] < x)
        {
            arr[i + 1] = arr[i];
            i--;
        }

        arr[i + 1] = x;
        size++;
    }

    // Delete maximum element
    void dequeue()
    {
        if (size == 0)
        {
            cout << "Priority Queue is empty\n";
            return;
        }

        cout << "Deleted: " << arr[0] << endl;

        for (int i = 0; i < size - 1; i++)
        {
            arr[i] = arr[i + 1];
        }

        size--;
    }

    // Display maximum element
    void peek()
    {
        if (size == 0)
        {
            cout << "Priority Queue is empty\n";
            return;
        }

        cout << "Maximum element: " << arr[0] << endl;
    }

    // Display queue
    void display()
    {
        if (size == 0)
        {
            cout << "Priority Queue is empty\n";
            return;
        }

        cout << "Priority Queue: ";

        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }

        cout << endl;
    }
};

int main()
{
    PriorityQueue pq;

    int choice, x;

    do
    {
        cout << "\n1. Enqueue";
        cout << "\n2. Dequeue";
        cout << "\n3. Peek";
        cout << "\n4. Display";
        cout << "\n5. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter element: ";
            cin >> x;
            pq.enqueue(x);
            break;

        case 2:
            pq.dequeue();
            break;

        case 3:
            pq.peek();
            break;

        case 4:
            pq.display();
            break;

        case 5:
            cout << "Exit\n";
            break;

        default:
            cout << "Invalid choice\n";
        }

    } while (choice != 5);

    return 0;
}