#include <iostream>
using namespace std;

class Search
{
    int arr[100];
    int n;

public:
    void input()
    {
        cout << "Enter number of elements: ";
        cin >> n;

        cout << "Enter elements in ascending or descending order: ";
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
    }

    void search(int key)
    {
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == key)
            {
                cout << "Element found at position " << i + 1 << endl;
                return;
            }
        }

        cout << "Element not found" << endl;
    }

    void binarySearch(int key)
    {
        if (n <= 0)
        {
            cout << "Array is empty\n";
            return;
        }

        int start = 0;
        int end = n - 1;

        bool ascending = (arr[start] <= arr[end]);

        while (start <= end)
        {
            int mid = start + (end - start) / 2;

            if (arr[mid] == key)
            {
                cout << "Element found at position " << mid + 1 << endl;
                return;
            }

            if (ascending)
            {
                if (arr[mid] < key)
                    start = mid + 1;
                else
                    end = mid - 1;
            }
            else
            {
                if (arr[mid] < key)
                    end = mid - 1;
                else
                    start = mid + 1;
            }
        }

        cout << "Element not found" << endl;
    }
};

int main()
{
    Search s;
    int choice, key;

    do
    {
        cout << "\nSearching Algorithms\n";
        cout << "1. Input array\n";
        cout << "2. Linear Search\n";
        cout << "3. Binary Search\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            s.input();
            break;

        case 2:

            cout << "Enter element to search: ";
            cin >> key;
            cout << "\nLinear Search:\n";
            s.search(key);
            break;

        case 3:

            cout << "Enter element to search: ";
            cin >> key;
            cout << "\nBinary Search:\n";
            s.binarySearch(key);
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