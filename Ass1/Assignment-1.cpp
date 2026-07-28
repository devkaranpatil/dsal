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
    void deleteAtEnd()
    {
        if (head == nullptr)
        {
            cout << "List is empty";
            return;
        }
        if (head->next == nullptr)
        {
            delete head;
            head = nullptr;
            cout << "Last node deleted";
            return;
        }
        Node *temp = head;

        while ((temp->next)->next != nullptr)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;

        cout << "Last node deleted";
    }
    void deleteAtBeginning()
    {
        if (head == nullptr)
        {
            cout << "List is empty";
            return;
        }

        Node *temp = head;
        head = head->next;
        delete temp;
        cout << "First node deleted";
    }
    void deleteAtIndex(int position)
    {
        if (position < 1)
        {
            cout << "Position is invalid\n";
            return;
        }

        if (position == 1)
        {
            deleteAtBeginning();
            return;
        }

        Node *temp = head;

        for (int i = 0; i < position - 2 && temp != nullptr; i++)
        {
            temp = temp->next;
        }

        if (temp == nullptr || temp->next == nullptr)
        {
            cout << "Position is invalid\n";
            return;
        }

        Node *nodeToDelete = temp->next;
        temp->next = nodeToDelete->next;

        delete nodeToDelete;

        displayAllElements();
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
             << "\nEnter 6 for Deleting the last node"
             << "\nEnter 7 for Deleting at an Index"
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

        case 6:
            linkList.deleteAtEnd();
            break;

        case 7:
            cout << "Enter position to delete: ";
            cin >> position;
            linkList.deleteAtIndex(position);
            break;

        default:
            cout << "Invalid input.\n";
        }

        cout << endl;

    } while (index != 0);

    return 0;
}