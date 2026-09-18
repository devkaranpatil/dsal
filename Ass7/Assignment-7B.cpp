#include <iostream>
#include <string>
using namespace std;

struct Product
{
    int productID;
    string productName;
    float price;
};

int partition(Product products[], int low, int high, bool ascending)
{
    float pivot = products[high].price;
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (ascending)
        {
            if (products[j].price <= pivot)
            {
                i++;
                swap(products[i], products[j]);
            }
        }
        else
        {
            if (products[j].price >= pivot)
            {
                i++;
                swap(products[i], products[j]);
            }
        }
    }

    swap(products[i + 1], products[high]);
    return i + 1;
}

void quickSort(Product products[], int low, int high, bool ascending)
{
    if (low < high)
    {
        int pi = partition(products, low, high, ascending);

        quickSort(products, low, pi - 1, ascending);
        quickSort(products, pi + 1, high, ascending);
    }
}

void displayProducts(Product products[], int n)
{
    cout << "\nProduct List:\n";
    cout << "---------------------------------------------\n";
    cout << "ID\tName\t\tPrice\n";
    cout << "---------------------------------------------\n";

    for (int i = 0; i < n; i++)
    {
        cout << products[i].productID << "\t"
             << products[i].productName << "\t\t"
             << products[i].price << endl;
    }

    cout << "---------------------------------------------\n";
}

int main()
{
    int n, choice;

    cout << "Enter number of products: ";
    cin >> n;

    Product products[n];

    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter details of Product " << i + 1 << ":\n";

        cout << "Product ID: ";
        cin >> products[i].productID;

        cout << "Product Name: ";
        cin >> products[i].productName;

        cout << "Price: ";
        cin >> products[i].price;
    }

    do
    {
        cout << "\n===== Product Management System =====\n";
        cout << "1. Display Products\n";
        cout << "2. Sort by Price - Ascending\n";
        cout << "3. Sort by Price - Descending\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            displayProducts(products, n);
            break;

        case 2:
            quickSort(products, 0, n - 1, true);
            cout << "\nProducts sorted by price in ascending order.\n";
            displayProducts(products, n);
            break;

        case 3:
            quickSort(products, 0, n - 1, false);
            cout << "\nProducts sorted by price in descending order.\n";
            displayProducts(products, n);
            break;

        case 4:
            cout << "\nExiting program...\n";
            break;

        default:
            cout << "\nInvalid choice!\n";
        }

    } while (choice != 4);

    return 0;
}