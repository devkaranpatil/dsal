#include <iostream>
using namespace std;

class Search
{
    int arr[100];
    int n;

    void display()
    {
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

public:
    void input()
    {
        cout << "Enter number of elements: ";
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            cout << "Enter element " << i + 1 << ":";
            cin >> arr[i];
        }
    }

    void bubbleSort()
    {
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
        display();
    }

    void insertionSort()
    {
        for (int i = 1; i < n; i++)
        {
            int key = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > key)
            {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
        display();
    }
};

int main()
{
    Search s;
    int choice, key;

    do
    {
        cout << "\nSorting Algorithms\n";
        cout << "1. Input array\n";
        cout << "2. Bubble Sort\n";
        cout << "3. Insertion Sort\n";
        cout << "4. Exit\n";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            s.input();
            break;

        case 2:
            cout << "\nThe sorted array is: " << endl;
            s.bubbleSort();
            break;

        case 3:
            cout << "\nThe sorted array is: " << endl;
            s.insertionSort();
            break;

        case 4:
            cout << "Exiting program.\n";
            break;

        default:
            cout << "Invalid choice! Please try again.\n";
            break;
        }
    } while (choice != 4);

    return 0;
}