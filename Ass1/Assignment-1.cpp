#include <iostream>
using namespace std;

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

class list
{
private:
    Node *head;

public:
    list()
    {
        head = nullptr;
    }
    void insertAtBeginning(int value)
    {
        Node *newNode = new Node(value);
        if (head == nullptr)
        {
            head = newNode;
            return;
        }
        newNode->next = head;
        head = newNode;
    }
    void insertAtEnd(int value)
    {
        Node *newNode = new Node(value);
        if (head == nullptr)
        {
            head = newNode;
            return;
        }
        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        return;
    }
    void displayAllElements()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
    void search(int key)
    {
        Node *temp = head;
        int position = 1;
        while (temp != nullptr)
        {
            if (temp->data == key)
            {
                cout << "Element of value " << key << " at position " << position;
                return;
            }
            position++;
            temp = temp->next;
        }
        cout << "Element not found in list";
        return;
    }
    void insertAtIndex(int value, int position)
    {
        if (position < 1)
        {
            cout << "Position is invalid";
            return;
        }
        Node *newNode = new Node(value);
        if (position == 1)
        {
            newNode->next = head;
            head = newNode;
            return;
        }
        Node *temp = head;
        for (int i = 0; i < position - 2 && temp != nullptr; ++i)
        {
            temp = temp->next;
        }
        if (temp == nullptr)
        {
            cout << "Position is invalid";
            delete newNode;
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
};

int main()
{
    int index = 1;
    int data;
    list linkList;
    do
    {
        cout << "\nEfficient Data Management Using Linked Lists\n"
             << "\nEnter 1 for Adding Element At the Beginning"
             << "\nEnter 2 for Adding Element At the End"
             << "\nEnter 3 for Adding Element At the Specific Index"
             << "\nEnter 4 for Displaying All Elements"
             << "\nEnter 5 for Searching an Element"
             << "\nEnter 0 to Exit"
             << "\nChoice: ";

        cin >> index;

        switch (index)
        {
        case 0:
            cout << "Exiting...\n";
            break;

        case 1:
            cout << "Enter data: ";
            cin >> data;
            linkList.insertAtBeginning(data);
            cout << "Element Added";
            break;

        case 2:
            cout << "Enter data: ";
            cin >> data;
            linkList.insertAtEnd(data);
            cout << "Element Added";
            break;

        case 3:
            int position;
            cout << "Enter the value to insert: ";
            cin >> data;
            cout << "Enter position to insert: ";
            cin >> position;
            linkList.insertAtIndex(data, position);
            break;

        case 4:
            linkList.displayAllElements();
            break;

        case 5:
            cout << "Enter element to search: ";
            cin >> data;
            linkList.search(data);
            break;
        default:
            cout << "Invalid input.\n";
        }

        cout << endl;

    } while (index != 0);

    return 0;
}