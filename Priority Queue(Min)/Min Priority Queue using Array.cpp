// Min Priority Queue using Array (Unsorted List)

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

    // Insert element (unsorted)
    void enqueue(int x)
    {
        if (size == 100)
        {
            cout << "Priority Queue is full." << endl;
            return;
        }

        arr[size] = x;
        size++;

        cout << x << " inserted." << endl;
    }

    // Delete minimum element
    void dequeue()
    {
        if (size == 0)
        {
            cout << "Priority Queue is empty." << endl;
            return;
        }

        int minIndex = 0;

        // Find minimum element
        for (int i = 1; i < size; i++)
        {
            if (arr[i] < arr[minIndex])
            {
                minIndex = i;
            }
        }

        cout << "Deleted minimum element: "
             << arr[minIndex] << endl;

        // Shift elements after minimum
        for (int i = minIndex; i < size - 1; i++)
        {
            arr[i] = arr[i + 1];
        }

        size--;
    }

    // Display minimum element
    void peek()
    {
        if (size == 0)
        {
            cout << "Priority Queue is empty." << endl;
            return;
        }

        int minIndex = 0;

        for (int i = 1; i < size; i++)
        {
            if (arr[i] < arr[minIndex])
            {
                minIndex = i;
            }
        }

        cout << "Minimum element: "
             << arr[minIndex] << endl;
    }

    // Display all elements
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
};

int main()
{
    PriorityQueue pq;

    int choice, x;

    do
    {
        cout << "\n===== MIN PRIORITY QUEUE =====";
        cout << "\n1. Enqueue";
        cout << "\n2. Dequeue (Delete Min)";
        cout << "\n3. Peek (Min)";
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
            cout << "Program ended." << endl;
            break;

        default:
            cout << "Invalid choice!" << endl;
        }

    } while (choice != 5);

    return 0;
}



 // Min Priority Queue using Array (Sorted List)

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

        // Shift larger elements to the right
        while (i >= 0 && arr[i] > x)
        {
            arr[i + 1] = arr[i];
            i--;
        }

        arr[i + 1] = x;
        size++;

        cout << x << " inserted." << endl;
    }

    // Delete minimum element
    void dequeue()
    {
        if (size == 0)
        {
            cout << "Priority Queue is empty." << endl;
            return;
        }

        cout << "Deleted: " << arr[0] << endl;

        // Shift elements to the left
        for (int i = 0; i < size - 1; i++)
        {
            arr[i] = arr[i + 1];
        }

        size--;
    }

    // Display minimum element
    void peek()
    {
        if (size == 0)
        {
            cout << "Priority Queue is empty." << endl;
            return;
        }

        cout << "Minimum element: " << arr[0] << endl;
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
};

int main()
{
    PriorityQueue pq;

    int choice, x;

    do
    {
        cout << "\n===== MIN PRIORITY QUEUE =====";
        cout << "\n1. Enqueue";
        cout << "\n2. Dequeue (Delete Min)";
        cout << "\n3. Peek (Min)";
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
            cout << "Program ended." << endl;
            break;

        default:
            cout << "Invalid choice!" << endl;
        }

    } while (choice != 5);

    return 0;
}