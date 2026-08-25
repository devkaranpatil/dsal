#include <iostream>
#include <limits>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int value)
    {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};

class list
{
private:
    Node *head;
    Node *tail;

public:
    list()
    {
        head = nullptr;
        tail = nullptr;
    }
    ~list()
    {
        while (head != nullptr)
        {
            Node *nodeToDelete = head;
            head = head->next;
            delete nodeToDelete;
        }
        tail = nullptr;
    }
    void insertAtBeginning(int value)
    {
        Node *newNode = new Node(value);
        if (head == nullptr)
        {
            head = tail = newNode;
            return;
        }
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    void insertAtEnd(int value)
    {
        Node *newNode = new Node(value);
        if (head == nullptr)
        {
            head = tail = newNode;
            return;
        }
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    void insertAtIndex(int value, int position)
    {
        if (position < 1)
        {
            cout << "Position is invalid";
            return;
        }
        if (position == 1)
        {
            insertAtBeginning(value);
            return;
        }
        Node *temp = head;
        for (int i = 1; i < position - 1 && temp != nullptr; ++i)
        {
            temp = temp->next;
        }
        if (temp == nullptr)
        {
            cout << "Position is invalid";
            return;
        }
        Node *newNode = new Node(value);
        newNode->next = temp->next;
        if (temp->next != nullptr)
        {
            temp->next->prev = newNode;
        }
        temp->next = newNode;
        newNode->prev = temp;
        if (newNode->next == nullptr)
        {
            tail = newNode;
        }
    }
    void displayAllElements()
    {
        if (head == nullptr)
        {
            cout << "List is empty";
            return;
        }

        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
    void search(int key)
    {
        if (head == nullptr)
        {
            cout << "List is empty";
            return;
        }

        Node *temp = head;
        int position = 1;
        while (temp != nullptr)
        {
            if (temp->data == key)
            {
                cout << "Linear search: element " << key << " found at position " << position;
                return;
            }
            position++;
            temp = temp->next;
        }
        cout << "Linear search: element " << key << " not found in the list";
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
            head = tail = nullptr;
            cout << "Last node deleted";
            return;
        }
        Node *nodeToDelete = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete nodeToDelete;
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
        if (head->next == nullptr)
        {
            head = tail = nullptr;
            delete temp;
            cout << "First node deleted";
            return;
        }
        head = head->next;
        head->prev = nullptr;
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
        for (int i = 1; i < position - 1 && temp != nullptr; i++)
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
        if (nodeToDelete->next != nullptr)
        {
            nodeToDelete->next->prev = temp;
        }
        else
        {
            tail = temp;
        }

        delete nodeToDelete;
        cout << "Node at position " << position << " has been deleted";
    }
    void reverseList()
    {
        if (head == nullptr)
        {
            cout << "List is empty";
            return;
        }

        Node *curr = head;
        Node *temp = nullptr;
        tail = head;

        while (curr != nullptr)
        {
            temp = curr;
            Node *nextNode = curr->next;
            curr->next = curr->prev;
            curr->prev = nextNode;
            curr = nextNode;
        }

        head = temp;
        cout << "List reversed";
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
             << "\nEnter 6 for Deleting the first node"
             << "\nEnter 7 for Deleting the last node"
             << "\nEnter 8 for Deleting at an Index"
             << "\nEnter 9 for Reversing A list"
             << "\nEnter 0 to Exit" << endl;

        cout << "Choice: ";
        if (!(cin >> index))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid choice. Please enter a number.\n";
            continue;
        }
        if (index < 0 || index > 10)
        {
            cout << "Invalid choice. Please enter a number between 0 and 10." << endl;
            continue;
        }

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
        {
            int position;
            cout << "Enter the value to insert: ";
            cin >> data;
            cout << "Enter position to insert: ";
            cin >> position;
            if (position < 1)
            {
                cout << "Position is invalid";
            }
            else
            {
                linkList.insertAtIndex(data, position);
            }
            break;
        }

        case 4:
            linkList.displayAllElements();
            break;

        case 5:
            cout << "Enter element to search: ";
            cin >> data;
            linkList.search(data);
            break;

        case 6:
            linkList.deleteAtBeginning();
            break;

        case 7:
            linkList.deleteAtEnd();
            break;

        case 8:
        {
            int position;
            cout << "Enter position to delete: ";
            cin >> position;
            if (position < 1)
            {
                cout << "Position is invalid";
            }
            else
            {
                linkList.deleteAtIndex(position);
            }
            break;
        }

        case 9:
            linkList.reverseList();
            break;

        default:
            cout << "Invalid input.\n";
        }

        cout << endl;

    } while (index != 0);

    return 0;
}
