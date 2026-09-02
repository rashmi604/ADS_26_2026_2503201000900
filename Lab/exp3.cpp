// EXPERIMENT 3 — RECURSION: FACTORIAL & Nth FIBONACCI

#include <iostream>
using namespace std;

// Recursive factorial
long long factorial(int n)
{
    if (n == 0 || n == 1)
        return 1;

    return n * factorial(n - 1);
}

// Recursive Fibonacci
long long fibonacci(int n)
{
    if (n == 0)
        return 0;

    if (n == 1)
        return 1;

    return fibonacci(n - 1) + fibonacci(n - 2);
}

// Recursive sum of first N natural numbers
int sumNatural(int n)
{
    if (n == 0)
        return 0;

    return n + sumNatural(n - 1);
}

// Recursive power
long long power(int a, int b)
{
    if (b == 0)
        return 1;

    return a * power(a, b - 1);
}

// Recursive GCD
int gcd(int a, int b)
{
    if (b == 0)
        return a;

    return gcd(b, a % b);
}

// Recursive function to print numbers 1 to N
void printNumbers(int n)
{
    if (n == 0)
        return;

    printNumbers(n - 1);
    cout << n << " ";
}

int main()
{
    int choice;

    do
    {
        cout << "\n========== RECURSION MENU ==========\n";
        cout << "1. Factorial\n";
        cout << "2. Nth Fibonacci Number\n";
        cout << "3. Sum of First N Natural Numbers\n";
        cout << "4. Power of a Number\n";
        cout << "5. GCD of Two Numbers\n";
        cout << "6. Print Numbers from 1 to N\n";
        cout << "7. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
            {
                int n;

                cout << "Enter N: ";
                cin >> n;

                if (n < 0)
                    cout << "Factorial is not defined for negative numbers\n";
                else
                    cout << "Factorial of " << n
                         << " = " << factorial(n) << endl;

                break;
            }

            case 2:
            {
                int n;

                cout << "Enter N: ";
                cin >> n;

                if (n < 0)
                    cout << "Invalid value\n";
                else
                    cout << "The " << n << "th Fibonacci number = "
                         << fibonacci(n) << endl;

                break;
            }

            case 3:
            {
                int n;

                cout << "Enter N: ";
                cin >> n;

                cout << "Sum = " << sumNatural(n) << endl;

                break;
            }

            case 4:
            {
                int a, b;

                cout << "Enter base: ";
                cin >> a;

                cout << "Enter exponent: ";
                cin >> b;

                cout << a << "^" << b
                     << " = " << power(a, b) << endl;

                break;
            }

            case 5:
            {
                int a, b;

                cout << "Enter two numbers: ";
                cin >> a >> b;

                cout << "GCD = " << gcd(a, b) << endl;

                break;
            }

            case 6:
            {
                int n;

                cout << "Enter N: ";
                cin >> n;

                cout << "Numbers: ";
                printNumbers(n);
                cout << endl;

                break;
            }

            case 7:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice\n";
        }

    } while (choice != 7);

    return 0;
}