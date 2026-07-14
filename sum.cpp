#include <iostream>
using namespace std;

class Sum
{
private:
    int a;
    int b;

public:
    Sum(int m, int n)
    {
        a = m;
        b = n;
    };
    int sum()
    {
        return (a + b);
    }
};

int main()
{
    int m, n;
    cout << "Enter number 1: ";
    cin >> n;
    cout << "Enter number 2: ";
    cin >> m;

    Sum answer(m, n);
    cout << "The sum of the two numbers is " << answer.sum() << endl;
}