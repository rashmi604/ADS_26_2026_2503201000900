// unsorted list
#include <iostream>
using namespace std;

class PriorityQueue
{
    struct Node
    {
        int info;
        Node *next;

        Node(int value)
        {
            info = value;
            next = NULL;
        }
    };

    Node *front;

public:

    PriorityQueue()
    {
        front = NULL;
    }

    // Insert element
    void insert(int value)
    {
        Node *newNode = new Node(value);

        if (front == NULL)
        {
            front = newNode;
        }
        else
        {
            newNode->next = front;
            front = newNode;
        }

        cout << value << " inserted successfully.\n";
    }

    // Delete maximum-priority element
    void deleteMax()
    {
        if (front == NULL)
        {
            cout << "Priority Queue is empty.\n";
            return;
        }

        Node *temp = front;
        Node *maxNode = front;
        Node *prev = NULL;
        Node *maxPrev = NULL;

        // Find maximum element
        while (temp != NULL)
        {
            if (temp->info > maxNode->info)
            {
                maxNode = temp;
                maxPrev = prev;
            }

            prev = temp;
            temp = temp->next;
        }

        // If maximum node is the first node
        if (maxNode == front)
        {
            front = front->next;
        }
        else
        {
            maxPrev->next = maxNode->next;
        }

        cout << "Deleted maximum element: " << maxNode->info << endl;

        delete maxNode;
    }

    // Display maximum element
    void peek()
    {
        if (front == NULL)
        {
            cout << "Priority Queue is empty.\n";
            return;
        }

        Node *temp = front;
        Node *maxNode = front;

        while (temp != NULL)
        {
            if (temp->info > maxNode->info)
            {
                maxNode = temp;
            }

            temp = temp->next;
        }

        cout << "Maximum element: " << maxNode->info << endl;
    }

    // Display all elements
    void display()
    {
        if (front == NULL)
        {
            cout << "Priority Queue is empty.\n";
            return;
        }

        Node *temp = front;

        cout << "Priority Queue: ";

        while (temp != NULL)
        {
            cout << temp->info << " ";
            temp = temp->next;
        }

        cout << endl;
    }
};

int main()
{
    PriorityQueue pq;
    int choice, value;

    while (true)
    {
        cout << "\n===== MAX PRIORITY QUEUE =====\n";
        cout << "1. Insert\n";
        cout << "2. Delete Max\n";
        cout << "3. Peek Max\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                pq.insert(value);
                break;

            case 2:
                pq.deleteMax();
                break;

            case 3:
                pq.peek();
                break;

            case 4:
                pq.display();
                break;

            case 5:
                cout << "Program ended.\n";
                return 0;

            default:
                cout << "Invalid choice!\n";
        }
    }

    return 0;
}

//sorted list
#include <iostream>
using namespace std;

class PriorityQueue
{
    struct Node
    {
        int info;
        Node *next;

        Node(int x)
        {
            info = x;
            next = NULL;
        }
    };

    Node *front;

public:

    PriorityQueue()
    {
        front = NULL;
    }

    // Insert element in sorted order
    void enqueue(int x)
    {
        Node *newNode = new Node(x);

        // If list is empty or x is maximum
        if (front == NULL || x > front->info)
        {
            newNode->next = front;
            front = newNode;
        }
        else
        {
            Node *temp = front;

            while (temp->next != NULL &&
                   temp->next->info >= x)
            {
                temp = temp->next;
            }

            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    // Delete maximum element
    void dequeue()
    {
        if (front == NULL)
        {
            cout << "Priority Queue is empty\n";
            return;
        }

        Node *temp = front;

        cout << "Deleted: " << temp->info << endl;

        front = front->next;

        delete temp;
    }

    // Display maximum element
    void peek()
    {
        if (front == NULL)
        {
            cout << "Priority Queue is empty\n";
            return;
        }

        cout << "Maximum element: " << front->info << endl;
    }

    // Display queue
    void display()
    {
        if (front == NULL)
        {
            cout << "Priority Queue is empty\n";
            return;
        }

        Node *temp = front;

        cout << "Priority Queue: ";

        while (temp != NULL)
        {
            cout << temp->info << " ";
            temp = temp->next;
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