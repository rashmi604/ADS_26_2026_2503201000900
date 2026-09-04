// Min Priority Queue using a Linked List (Unsorted List)

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

    // Insert element
    void enqueue(int x)
    {
        Node *newNode = new Node(x);

        newNode->next = front;
        front = newNode;

        cout << x << " inserted." << endl;
    }

    // Delete minimum element
    void dequeue()
    {
        if (front == NULL)
        {
            cout << "Priority Queue is empty." << endl;
            return;
        }

        Node *temp = front;
        Node *minNode = front;
        Node *prev = NULL;
        Node *minPrev = NULL;

        // Find minimum element
        while (temp != NULL)
        {
            if (temp->info < minNode->info)
            {
                minNode = temp;
                minPrev = prev;
            }

            prev = temp;
            temp = temp->next;
        }

        // If minimum element is at front
        if (minNode == front)
        {
            front = front->next;
        }
        else
        {
            minPrev->next = minNode->next;
        }

        cout << "Deleted minimum element: "
             << minNode->info << endl;

        delete minNode;
    }

    // Display minimum element
    void peek()
    {
        if (front == NULL)
        {
            cout << "Priority Queue is empty." << endl;
            return;
        }

        Node *temp = front;
        Node *minNode = front;

        while (temp != NULL)
        {
            if (temp->info < minNode->info)
            {
                minNode = temp;
            }

            temp = temp->next;
        }

        cout << "Minimum element: "
             << minNode->info << endl;
    }

    // Display all elements
    void display()
    {
        if (front == NULL)
        {
            cout << "Priority Queue is empty." << endl;
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


// Min Priority Queue using a Linked List (Sorted List)

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

        // If list is empty or x is minimum
        if (front == NULL || x < front->info)
        {
            newNode->next = front;
            front = newNode;
        }
        else
        {
            Node *temp = front;

            while (temp->next != NULL &&
                   temp->next->info <= x)
            {
                temp = temp->next;
            }

            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    // Delete minimum element
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

    // Display minimum element
    void peek()
    {
        if (front == NULL)
        {
            cout << "Priority Queue is empty\n";
            return;
        }

        cout << "Minimum element: " << front->info << endl;
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