#include <iostream>
using namespace std;
#define SIZE 10

class HashTable
{
private:
    int table[SIZE];

public:
    HashTable()
    {
        for (int i = 0; i < SIZE; i++)
        {
            table[i] = -1;
        }
    }

    void insertLinear(int key)
    {
        int index = key % SIZE;

        for (int i = 0; i < SIZE; i++)
        {
            int pos = (index + i) % SIZE;
            if (table[pos] == -1)
            {
                table[pos] = key;
                cout << "Inserted " << key << " at index " << pos << endl;
                return;
            }
        }
        cout << "Hash table is full. Cannot insert" << key << endl;
    }
    void insertQuadratic(int key)
    {
        int index = key % SIZE;

        for (int i = 0; i < SIZE; i++)
        {
            int pos = (index + i * i) % SIZE;
            if (table[pos] == -1)
            {
                table[pos] = key;
                cout << "Inserted " << key << " at index " << pos << endl;
                return;
            }
        }
        cout << "Hash table is full. Cannot insert" << key << endl;
    }

    void search(int key)
    {
        int index = key % SIZE;

        for (int i = 0; i < SIZE; i++)
        {
            int pos = (index + i) % SIZE;
            if (table[pos] == key)
            {
                cout << "Found " << key << " at index " << pos << endl;
                return;
            }
            else if (table[pos] == -1)
            {
                cout << key << " not found in the hash table." << endl;
                return;
            }
        }
    }
    void deleteElement(int key)
    {
        int index = key % SIZE;
        for (int i = 0; i < SIZE; i++)
        {
            int pos = (index + i) % SIZE;
            if (table[pos] == key)
            {
                table[pos] = -1;
                cout << "Deleted " << key << " from index " << pos << endl;
                return;
            }
            else if (table[pos] == -1)
            {
                cout << key << " not found in the hash table." << endl;
                return;
            }
        }
    }
    void display()
    {
        cout << "Hash Table: ";
        for (int i = 0; i < SIZE; i++)
        {
            if (table[i] != -1)
                cout << table[i] << " ";
            else
                cout << "- ";
        }
        cout << endl;
    }
};

int main()
{
    HashTable ht;
    int choice, key;

    do
    {
        cout << "1. Insert (Linear Probing)" << endl;
        cout << "2. Insert (Quadratic Probing)" << endl;
        cout << "3. Search" << endl;
        cout << "4. Delete" << endl;
        cout << "5. Display" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter key to insert: ";
            cin >> key;
            ht.insertLinear(key);
            break;
        case 2:
            cout << "Enter key to insert: ";
            cin >> key;
            ht.insertQuadratic(key);
            break;
        case 3:
            cout << "Enter key to search: ";
            cin >> key;
            ht.search(key);
            break;
        case 4:
            cout << "Enter key to delete: ";
            cin >> key;
            ht.deleteElement(key);
            break;
        case 5:
            ht.display();
            break;
        case 6:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}