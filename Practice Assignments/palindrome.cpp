#include <iostream>
#include <string>
using namespace std;

class Palindrome
{
private:
    int number;
    string str;
    bool isNumber;

public:
    Palindrome(int a)
    {
        number = a;
        isNumber = true;
    }

    Palindrome(string s)
    {
        str = s;
        isNumber = false;
    }

    void palindrome()
    {
        if (isNumber)
        {
            int copy = number;
            int reverse_number = 0;

            while (copy)
            {
                int digit = copy % 10;
                reverse_number = reverse_number * 10 + digit;
                copy /= 10;
            }

            if (number == reverse_number)
                cout << "The number is a palindrome.\n";
            else
                cout << "The number is not a palindrome.\n";
        }
        else
        {
            bool flag = true;

            for (int i = 0, j = str.length() - 1; i < j; i++, j--)
            {
                if (str[i] != str[j])
                {
                    flag = false;
                    break;
                }
            }

            if (flag)
                cout << "The string is a palindrome.\n";
            else
                cout << "The string is not a palindrome.\n";
        }
    }
};

int main()
{
    int choice;

    cout << "1. Check Number\n";
    cout << "2. Check String\n";
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1)
    {
        int num;
        cout << "Enter a number: ";
        cin >> num;

        Palindrome p(num);
        p.palindrome();
    }
    else if (choice == 2)
    {
        string s;
        cout << "Enter a string: ";
        cin >> s;

        Palindrome p(s);
        p.palindrome();
    }
    else
    {
        cout << "Invalid choice!\n";
    }

    return 0;
}