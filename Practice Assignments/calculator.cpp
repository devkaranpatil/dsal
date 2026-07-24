#include <iostream>
using namespace std;

class Number
{
private:
    int a, b;

public:
    Number(int m, int n)
    {
        a = m;
        b = n;
    }

    int sum()
    {
        return a + b;
    }

    int subtract()
    {
        if (a >= b)
            return a - b;
        return b - a;
    }

    int multiply()
    {
        return a * b;
    }

    int division()
    {
        if (b == 0)
        {
            cout << "Division by zero is not possible." << endl;
            return 0;
        }
        return a / b;
    }
};

int main()
{
    int index = 1;
    int num1, num2;

    do
    {
        cout << "Enter number 1: ";
        cin >> num1;

        cout << "Enter number 2: ";
        cin >> num2;

        Number answer(num1, num2);

        cout << "\nEnter 1 for Addition"
             << "\nEnter 2 for Subtraction"
             << "\nEnter 3 for Multiplication"
             << "\nEnter 4 for Division"
             << "\nEnter 0 to Exit"
             << "\nChoice: ";

        cin >> index;

        switch (index)
        {
        case 0:
            cout << "Exiting...\n";
            break;

        case 1:
            cout << "The addition of two number is " << answer.sum() << endl;
            break;

        case 2:
            cout << "The substraction of two number is " << answer.subtract() << endl;
            break;

        case 3:
            cout << "The multiplicatin of two number is " << answer.multiply() << endl;
            break;

        case 4:
            cout << "The division of two number is  " << answer.division() << endl;
            break;

        default:
            cout << "Invalid input.\n";
        }

        cout << endl;

    } while (index != 0);

    return 0;
}