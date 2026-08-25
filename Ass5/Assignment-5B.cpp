#include <iostream>
#include <string>
using namespace std;

class studentDetails
{
public:
    string name;
    int rollNo;
    string branch;
    float cgpa;

    studentDetails() {}
    studentDetails(string n, int r, string b, float c)
    {
        name = n;
        rollNo = r;
        branch = b;
        cgpa = c;
    }
};

class Node
{
public:
    studentDetails data;
    Node *next;
    Node *prev;
    Node(studentDetails d)
    {
        data = (d);
        next = (nullptr);
        prev = (nullptr);
    }
};

class list
{
private:
    Node *head;
    Node *tail;

    void displayNode(Node *Node)
    {
        cout << Node->data.rollNo << " ";
        cout << Node->data.name << " ";
        cout << Node->data.branch << " ";
        cout << Node->data.cgpa << endl;
    }

public:
    list()
    {
        head = nullptr;
        tail = nullptr;
    }
    void insertAtBeginning(studentDetails value)
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
    void insertAtEnd(studentDetails value)
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
    void insertAtIndex(studentDetails value, int position)
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
            cout << temp->data.rollNo << " ";
            cout << temp->data.name << " ";
            cout << temp->data.branch << " ";
            cout << temp->data.cgpa << endl;
            temp = temp->next;
        }
    }
    void searchByRollNo(int key)
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
            if (temp->data.rollNo == key)
            {
                cout << "Student found" << endl;
                displayNode(temp);
                return;
            }
            position++;
            temp = temp->next;
        }
        cout << "Student not found in list";
    }
    void searchByName(string key)
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
            if (temp->data.name == key)
            {
                cout << "Student found" << endl;
                displayNode(temp);
                return;
            }
            position++;
            temp = temp->next;
        }
        cout << "Student not found in list";
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
            cout << "Student deleted";
            return;
        }
        Node *nodeToDelete = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete nodeToDelete;
        cout << "Student deleted";
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
            cout << "Student deleted";
            return;
        }
        head = head->next;
        head->prev = nullptr;
        delete temp;
        cout << "Student deleted";
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

void studentInput(studentDetails &data)
{
    cout << "Enter Name :";
    cin >> data.name;
    cout << "Enter Roll Number :";
    cin >> data.rollNo;
    cout << "Enter Branch :";
    cin >> data.branch;
    cout << "Enter Cgpa :";
    cin >> data.cgpa;
}
int main()
{
    int rollNo;
    string name;
    int index = 1;
    studentDetails data;
    list linkList;
    do
    {
        cout << "\nStudent Data Management System\n"
             << "\nEnter 1 for Adding Element At the Beginning"
             << "\nEnter 2 for Adding Element At the End"
             << "\nEnter 3 for Adding Element At the Specific Index"
             << "\nEnter 4 for Displaying All Elements"
             << "\nEnter 5 for Searching an Element by Roll Number"
             << "\nEnter 6 for Searching an Element by Name"
             << "\nEnter 7 for Deleting the first node"
             << "\nEnter 8 for Deleting the last node"
             << "\nEnter 9 for Deleting at an Index"
             << "\nEnter 10 for Reversing A list"
             << "\nEnter 0 to Exit" << endl;

        cout << "Choice: ";
        cin >> index;
        cin.ignore(10000, '\n');
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
            studentInput(data);
            linkList.insertAtBeginning(data);
            cout << "Element Added";
            break;

        case 2:
            cout << "Enter data: ";
            studentInput(data);
            linkList.insertAtEnd(data);
            cout << "Element Added";
            break;

        case 3:
        {
            int position;
            cout << "Enter the value to insert: ";
            studentInput(data);
            cout << "Enter position to insert: ";
            cin >> position;
            cin.ignore(10000, '\n');
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
            cout << "Enter Roll Number to search: ";
            cin >> rollNo;
            cin.ignore(10000, '\n');
            linkList.searchByRollNo(rollNo);
            break;

        case 6:
            cout << "Enter Name to search: ";
            cin >> name;
            cin.ignore(10000, '\n');
            linkList.searchByName(name);
            break;

        case 7:
            linkList.deleteAtBeginning();
            break;

        case 8:
            linkList.deleteAtEnd();
            break;

        case 9:
        {
            int position;
            cout << "Enter position to delete: ";
            cin >> position;
            cin.ignore(10000, '\n');
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

        case 10:
            linkList.reverseList();
            break;

        default:
            cout << "Invalid input.\n";
        }

        cout << endl;

    } while (index != 0);

    return 0;
}