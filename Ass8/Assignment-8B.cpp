#include <iostream>
using namespace std;
#define SIZE 10

class Node
{
public:
    int data;
    Node *next;

    Node(int value)
    {
        data = value;
        next = nullptr;
    }
};

class HashTable
{
private:
    Node *table[SIZE];

public:
    HashTable()
    {
        for (int i = 0; i < SIZE; i++)
        {
            table[i] = nullptr;
        }
    }

    void insert(int key)
    {
        Node *newNode = new Node(key);
        int index = key % SIZE;
        if (table[index] == nullptr)
        {
            table[index] = new Node(key);
            cout << "Inserted " << key << " at index " << key << endl;
            return;
        }
        Node *temp = table[index];
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        return;
    }

    void search(int key)
    {
        int index = key % SIZE;

        if (table[index] == nullptr)
        {
            cout << "Element not found in hash table." << endl;
            return;
        }

        Node *temp = table[index];
        int position = 1;
        while (temp != nullptr)
        {
            if (temp->data == key)
            {
                cout << "Element of value " << key << " found at position " << position;
                return;
            }
            position++;
            temp = temp->next;
        }
        cout << "Element not found in list";
    }
    void display()
    {
        cout << "Hash Table: ";
        for (int i = 0; i < SIZE; i++)
        {
            if (table[i] != nullptr)
            {
                Node *temp = table[i];
                while (temp != nullptr)
                {
                    cout << temp->data << " ";
                    temp = temp->next;
                }
            }
            else
            {
                cout << "- ";
            }
            cout << endl;
        }
    }
};
int main()
{
    HashTable ht;
    int choice, key;

    do
    {
        cout << "1. Insert" << endl;
        cout << "2. Search" << endl;
        cout << "3. Display" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter key to insert: ";
            cin >> key;
            ht.insert(key);
            break;
        case 2:
            cout << "Enter key to search: ";
            cin >> key;
            ht.search(key);
            break;
        case 3:
            ht.display();
            break;
        case 4:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}