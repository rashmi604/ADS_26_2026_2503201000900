#include <iostream>
#include <stack>
#include <string>
#include <cctype>
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

// Function to convert infix to postfix
string infixToPostfix(string infix)
{
    string postfix = "";
    stack<char> st;

    for (char ch : infix)
    {
        // If operand, add to postfix
        if (isalnum(ch))
        {
            postfix += ch;
        }
        // If '(' push into stack
        else if (ch == '(')
        {
            st.push(ch);
        }
        // If ')' pop until '('
        else if (ch == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                postfix += st.top();
                st.pop();
            }

            if (!st.empty())
                st.pop(); // Remove '('
        }
        // Operator
        else
        {
            while (!st.empty() &&
                   (precedence(st.top()) > precedence(ch) ||
                   (precedence(st.top()) == precedence(ch) && ch != '^')))
            {
                postfix += st.top();
                st.pop();
            }

            st.push(ch);
        }
    }

    // Pop remaining operators
    while (!st.empty())
    {
        postfix += st.top();
        st.pop();
    }

    return postfix;
}

int main()
{
    string infix;

    cout << "Enter Infix Expression: ";
    cin >> infix;

    cout << "Postfix Expression: " << infixToPostfix(infix) << endl;

    return 0;
}