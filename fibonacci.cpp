#include <iostream>
using namespace std;

int main()
{
    int a = 0;
    int b = 1;
    int number;
    cout << "Enter a number to print fibonacci numbers till: ";
    cin >> number;
    int arr[number] = {0, 1};
    for (int i = 2; i < number; i++)
    {
        int temp = a;
        a = b;
        b = b + temp;
        arr[i] = b;
    }
    for (int i = 0; i < number; i++)
    {
        cout << arr[i] << " ";
    }
}