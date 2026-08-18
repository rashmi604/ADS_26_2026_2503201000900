#include <iostream>
using namespace std;

// Call by Value
void swapByValue(int first, int second)
{
    int temp = first;
    first = second;
    second = temp;

    cout << "\nInside Call by Value Function:" << endl;
    cout << "First Number: " << first << endl;
    cout << "Second Number: " << second << endl;
}

// Call by Reference
void swapByReference(int &first, int &second)
{
    int temp = first;
    first = second;
    second = temp;

    cout << "\nInside Call by Reference Function:" << endl;
    cout << "First Number: " << first << endl;
    cout << "Second Number: " << second << endl;
}

// Call by Address
void swapByAddress(int *first, int *second)
{
    int temp = *first;
    *first = *second;
    *second = temp;

    cout << "\nInside Call by Address Function:" << endl;
    cout << "First Number: " << *first << endl;
    cout << "Second Number: " << *second << endl;
}

int main()
{
    int firstNumber, secondNumber;

    // Taking input
    cout << "Enter first number: ";
    cin >> firstNumber;

    cout << "Enter second number: ";
    cin >> secondNumber;

    // ---------------- Call by Value ----------------
    cout << "\n========== CALL BY VALUE ==========" << endl;

    cout << "Before function call:" << endl;
    cout << "First Number: " << firstNumber << endl;
    cout << "Second Number: " << secondNumber << endl;

    swapByValue(firstNumber, secondNumber);

    cout << "\nAfter function call:" << endl;
    cout << "First Number: " << firstNumber << endl;
    cout << "Second Number: " << secondNumber << endl;


    // ---------------- Call by Reference ----------------
    cout << "\n========== CALL BY REFERENCE ==========" << endl;

    cout << "Before function call:" << endl;
    cout << "First Number: " << firstNumber << endl;
    cout << "Second Number: " << secondNumber << endl;

    swapByReference(firstNumber, secondNumber);

    cout << "\nAfter function call:" << endl;
    cout << "First Number: " << firstNumber << endl;
    cout << "Second Number: " << secondNumber << endl;


    // ---------------- Call by Address ----------------
    cout << "\n========== CALL BY ADDRESS ==========" << endl;

    cout << "Before function call:" << endl;
    cout << "First Number: " << firstNumber << endl;
    cout << "Second Number: " << secondNumber << endl;

    swapByAddress(&firstNumber, &secondNumber);

    cout << "\nAfter function call:" << endl;
    cout << "First Number: " << firstNumber << endl;
    cout << "Second Number: " << secondNumber << endl;

    return 0;
}