#include <iostream>
using namespace std;

int fact(int n)
{
    if (n == 0 || n == 1)
        return 1;
    else
        return n * fact(n - 1);
}

int main()
{
    int n = 5;

    cout << "Factorial = " << fact(n);

    return 0;
}   



// function
#include <iostream>
using namespace std;

void fun1(int n)
{
    if (n > 0)
    {
        cout << n << " ";
        fun1(n - 1);
    }
}

void fun2(int n)
{
    if (n > 0)
    {
        fun2(n - 1);
        cout << n << " ";
    }
}

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;

    cout << "Fun1: ";
    fun1(n);

    cout << "\nFun2: ";
    fun2(n);

    return 0;
}