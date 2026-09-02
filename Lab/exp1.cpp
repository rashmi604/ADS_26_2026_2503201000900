//  EXPERIMENT 1 — STACK, INFIX TO POSTFIX & POSTFIX EVALUATION

#include <iostream>
#include <stack>
#include <string>
#include <cctype>
#include <cmath>
using namespace std;

// Function to return precedence of operators
int precedence(char op)
{
    if (op == '^')
        return 3;
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return 0;
}

// Function to check whether operator is right associative
bool isRightAssociative(char op)
{
    return op == '^';
}

// Infix to Postfix
string infixToPostfix(string infix)
{
    stack<char> st;
    string postfix = "";

    for (int i = 0; i < infix.length(); i++)
    {
        char ch = infix[i];

        if (ch == ' ')
            continue;

        // Operand
        if (isalnum(ch))
        {
            postfix += ch;
        }

        // Opening bracket
        else if (ch == '(')
        {
            st.push(ch);
        }

        // Closing bracket
        else if (ch == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                postfix += st.top();
                st.pop();
            }

            if (!st.empty())
                st.pop();
        }

        // Operator
        else
        {
            while (!st.empty() && st.top() != '(' &&
                   (precedence(st.top()) > precedence(ch) ||
                   (precedence(st.top()) == precedence(ch) &&
                    !isRightAssociative(ch))))
            {
                postfix += st.top();
                st.pop();
            }

            st.push(ch);
        }
    }

    while (!st.empty())
    {
        postfix += st.top();
        st.pop();
    }

    return postfix;
}

// Postfix evaluation
int applyOperation(int a, int b, char op)
{
    switch (op)
    {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        case '^': return pow(a, b);
    }

    return 0;
}

int evaluatePostfix(string postfix)
{
    stack<int> st;

    for (char ch : postfix)
    {
        if (isdigit(ch))
        {
            st.push(ch - '0');
        }
        else
        {
            int b = st.top();
            st.pop();

            int a = st.top();
            st.pop();

            st.push(applyOperation(a, b, ch));
        }
    }

    return st.top();
}

// Stack implementation
class Stack
{
    int *arr;
    int top;
    int size;

public:
    Stack(int n)
    {
        size = n;
        arr = new int[size];
        top = -1;
    }

    void push(int value)
    {
        if (top == size - 1)
        {
            cout << "Stack Overflow\n";
            return;
        }

        arr[++top] = value;
        cout << value << " pushed into stack\n";
    }

    void pop()
    {
        if (top == -1)
        {
            cout << "Stack Underflow\n";
            return;
        }

        cout << arr[top--] << " popped from stack\n";
    }

    void display()
    {
        if (top == -1)
        {
            cout << "Stack is empty\n";
            return;
        }

        cout << "Stack contents: ";

        for (int i = top; i >= 0; i--)
            cout << arr[i] << " ";

        cout << endl;
    }

    ~Stack()
    {
        delete[] arr;
    }
};

int main()
{
    int n;

    cout << "Enter size of stack: ";
    cin >> n;

    Stack s(n);

    int choice, value;

    do
    {
        cout << "\n--- STACK MENU ---\n";
        cout << "1. PUSH\n";
        cout << "2. POP\n";
        cout << "3. DISPLAY\n";
        cout << "4. Infix to Postfix\n";
        cout << "5. Evaluate Postfix\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                s.push(value);
                break;

            case 2:
                s.pop();
                break;

            case 3:
                s.display();
                break;

            case 4:
            {
                string infix;

                cout << "Enter infix expression: ";
                cin >> infix;

                string postfix = infixToPostfix(infix);

                cout << "Postfix expression: " << postfix << endl;
                break;
            }

            case 5:
            {
                string postfix;

                cout << "Enter postfix expression using single-digit operands: ";
                cin >> postfix;

                cout << "Result = "
                     << evaluatePostfix(postfix) << endl;

                break;
            }

            case 6:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice\n";
        }

    } while (choice != 6);

    return 0;
}