#include <iostream>
#include <limits>
using namespace std;

class Contact
{
public:
    string name;
    string phone;
    string email;

    Contact() {};
    Contact(string n, string p, string e)
    {
        name = n;
        phone = p;
        email = e;
    }
};

class Node
{
public:
    Contact data;
    Node *next;

    Node(const Contact &value)
        : data(value), next(nullptr)
    {
    }
};

class Contactlist
{
private:
    Node *head;

    bool hasDuplicatePhone(const string &phone) const
    {
        for (Node *temp = head; temp != nullptr; temp = temp->next)
        {
            if (temp->data.phone == phone)
            {
                return true;
            }
        }
        return false;
    }

    bool hasDuplicateEmail(const string &email) const
    {
        for (Node *temp = head; temp != nullptr; temp = temp->next)
        {
            if (temp->data.email == email)
            {
                return true;
            }
        }
        return false;
    }

    bool canAdd(const Contact &value) const
    {
        const bool duplicatePhone = hasDuplicatePhone(value.phone);
        const bool duplicateEmail = hasDuplicateEmail(value.email);

        if (duplicatePhone)
        {
            cout << "A contact with this phone number already exists.\n";
        }
        if (duplicateEmail)
        {
            cout << "A contact with this email already exists.\n";
        }
        return !duplicatePhone && !duplicateEmail;
    }

public:
    Contactlist()
    {
        head = nullptr;
    }
    bool insertAtBeginning(const Contact &value)
    {
        if (!canAdd(value))
        {
            return false;
        }
        Node *newNode = new Node(value);
        if (head == nullptr)
        {
            head = newNode;
            return true;
        }
        newNode->next = head;
        head = newNode;
        return true;
    }
    bool insertAtEnd(const Contact &value)
    {
        if (!canAdd(value))
        {
            return false;
        }
        Node *newNode = new Node(value);
        if (head == nullptr)
        {
            head = newNode;
            return true;
        }
        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        return true;
    }
    bool insertAtIndex(const Contact &value, int position)
    {
        if (position < 1)
        {
            cout << "Position is invalid";
            return false;
        }
        if (!canAdd(value))
        {
            return false;
        }
        Node *newNode = new Node(value);
        if (position == 1)
        {
            newNode->next = head;
            head = newNode;
            return true;
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
            return false;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        return true;
    }
    void displayAllContacts()
    {
        if (head == nullptr)
        {
            cout << "List is empty";
            return;
        }

        Node *temp = head;
        while (temp != nullptr)
        {
            cout << "Name: " << temp->data.name << endl;
            cout << "Phone Number: " << temp->data.phone << endl;
            cout << "Email: " << temp->data.email << endl;
            cout << endl;
            temp = temp->next;
        }
    }
    void search(const string &key)
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
                cout << "Contact Name of " << key << " is found at position " << position;
                return;
            }
            position++;
            temp = temp->next;
        }
        cout << "Contact not found in list";
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
            cout << "Last Contact deleted";
            return;
        }
        Node *temp = head;

        while ((temp->next)->next != nullptr)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;

        cout << "Last Contact deleted";
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
        cout << "First Contact deleted";
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

        displayAllContacts();
    }
    void reverseList()
    {
        if (head == nullptr)
        {
            cout << "List is empty";
            return;
        }

        Node *curr = head;
        Node *prev = nullptr;
        Node *nextNode = nullptr;

        while (curr != nullptr)
        {
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        head = prev;
        displayAllContacts();
    }
};

void readContact(Contact &data)
{
    cout << "Enter Name : ";
    getline(cin, data.name);

    cout << "Enter Phone : ";
    getline(cin, data.phone);

    cout << "Enter Email : ";
    getline(cin, data.email);
}

void discardLine()
{
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main()
{
    int index = 1;

    Contact data;

    Contactlist linkList;

    do
    {
        cout << "\nEfficient Contact Management System Using Linked Lists\n"
             << "\nEnter 1 for Adding Contact At the Beginning"
             << "\nEnter 2 for Adding Contact At the End"
             << "\nEnter 3 for Adding Contact At the Specific Index"
             << "\nEnter 4 for Displaying All Contacts"
             << "\nEnter 5 for Searching an Contact"
             << "\nEnter 6 for Deleting the first Contact"
             << "\nEnter 7 for Deleting the last Contact"
             << "\nEnter 8 for Deleting at an Index"
             << "\nEnter 9 for Reversing A list"
             << "\nEnter 0 to Exit" << endl;

        cout << "Choice: ";
        if (!(cin >> index))
        {
            cin.clear();
            discardLine();
            cout << "Invalid choice. Please enter a number between 0 and 9." << endl;
            continue;
        }
        discardLine();
        if (index < 0 || index > 9)
        {
            cout << "Invalid choice. Please enter a number between 0 and 9." << endl;
            continue;
        }

        switch (index)
        {
        case 0:
            cout << "Exiting...\n";
            break;

        case 1:
            readContact(data);
            if (linkList.insertAtBeginning(data))
            {
                cout << "Contact Added";
            }
            break;

        case 2:
            readContact(data);
            if (linkList.insertAtEnd(data))
            {
                cout << "Contact Added";
            }
            break;

        case 3:
        {
            int position;
            readContact(data);
            cout << "Enter position to insert: ";
            if (!(cin >> position))
            {
                cin.clear();
                discardLine();
                cout << "Position is invalid";
            }
            else if (position < 1)
            {
                cout << "Position is invalid";
            }
            else if (linkList.insertAtIndex(data, position))
            {
                cout << "Contact Added";
            }
            discardLine();
            break;
        }

        case 4:
            linkList.displayAllContacts();
            break;

        case 5:
            cout << "Enter the name of contact to search: ";
            getline(cin, data.name);
            linkList.search(data.name);
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
            if (!(cin >> position))
            {
                cin.clear();
                discardLine();
                cout << "Position is invalid";
            }
            else if (position < 1)
            {
                cout << "Position is invalid";
            }
            else
            {
                linkList.deleteAtIndex(position);
            }
            discardLine();
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
