#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class Contact
{
public:
    string name;
    string phone;
    string email;

    Contact() {}

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
    {
        data = value;
        next = nullptr;
    }
};

class ContactList
{
private:
    Node *head;

    bool hasDuplicatePhone(const string &phone, Node *ignore = nullptr) const
    {
        Node *temp = head;

        while (temp != nullptr)
        {
            if (temp != ignore && temp->data.phone == phone)
            {
                return true;
            }

            temp = temp->next;
        }

        return false;
    }

    bool hasDuplicateEmail(const string &email, Node *ignore = nullptr) const
    {
        Node *temp = head;

        while (temp != nullptr)
        {
            if (temp != ignore && temp->data.email == email)
            {
                return true;
            }

            temp = temp->next;
        }

        return false;
    }

    bool isValidPhone(const string &phone) const
    {
        if (phone.length() != 10)
        {
            cout << "Phone number must contain exactly 10 digits.\n";
            return false;
        }

        for (char c : phone)
        {
            if (!isdigit(c))
            {
                cout << "Phone number must contain only digits.\n";
                return false;
            }
        }

        return true;
    }

    bool isValidEmail(const string &email) const
    {
        int at = email.find('@');
        int dot = email.find('.', at);

        if (at <= 0)
        {
            cout << "Invalid email: missing '@'.\n";
            return false;
        }

        if (dot == string::npos || dot <= at + 1 || dot == email.length() - 1)
        {
            cout << "Invalid email domain.\n";
            return false;
        }

        if (email.find(' ') != string::npos)
        {
            cout << "Email cannot contain spaces.\n";
            return false;
        }

        return true;
    }

    bool isValidName(const string &name) const
    {
        if (name.empty())
        {
            cout << "Name cannot be empty.\n";
            return false;
        }

        for (char c : name)
        {
            if (!isalpha(c) && c != ' ')
            {
                cout << "Name can contain only alphabets and spaces.\n";
                return false;
            }
        }

        return true;
    }

    void displayContact(const Contact &contact) const
    {
        cout << "Name  : " << contact.name << endl;
        cout << "Phone : " << contact.phone << endl;
        cout << "Email : " << contact.email << endl;
    }

    int countContactsByName(const string &name) const
    {
        int count = 0;

        Node *temp = head;

        while (temp != nullptr)
        {
            if (temp->data.name == name)
            {
                count++;
            }

            temp = temp->next;
        }

        return count;
    }

public:
    ContactList()
    {
        head = nullptr;
    }

    void addContact()
    {
        Contact data;

        do
        {
            cout << "Enter Name: ";
            getline(cin, data.name);
        } while (!isValidName(data.name));

        while (true)
        {
            cout << "Enter Phone: ";
            getline(cin, data.phone);

            if (!isValidPhone(data.phone))
            {
                continue;
            }

            if (hasDuplicatePhone(data.phone))
            {
                cout << "A contact with this phone number already exists.\n";
                continue;
            }

            break;
        }

        while (true)
        {
            cout << "Enter Email: ";
            getline(cin, data.email);

            if (!isValidEmail(data.email))
            {
                continue;
            }

            if (hasDuplicateEmail(data.email))
            {
                cout << "A contact with this email already exists.\n";
                continue;
            }

            break;
        }

        Node *newNode = new Node(data);

        if (head == nullptr ||
            data.name < head->data.name)
        {
            newNode->next = head;
            head = newNode;
        }
        else
        {
            Node *temp = head;

            while (temp->next != nullptr &&
                   temp->next->data.name <= data.name)
            {
                temp = temp->next;
            }

            newNode->next = temp->next;
            temp->next = newNode;
        }

        cout << "\nContact added successfully.\n";
    }

    void displayAllContacts() const
    {
        if (head == nullptr)
        {
            cout << "Contact list is empty.\n";
            return;
        }

        Node *temp = head;
        int count = 1;

        cout << "\nCONTACTS\n";

        while (temp != nullptr)
        {
            cout << "\nContact " << count << endl;
            cout << "-----------------------------\n";

            displayContact(temp->data);

            temp = temp->next;
            count++;
        }
    }

    void search(const string &name) const
    {
        if (head == nullptr)
        {
            cout << "Contact list is empty.\n";
            return;
        }

        Node *temp = head;
        int count = 0;

        while (temp != nullptr)
        {
            if (temp->data.name == name)
            {
                count++;
                cout << "\nMatch " << count << endl;
                cout << "-----------------\n";
                displayContact(temp->data);
            }

            temp = temp->next;
        }

        if (count == 0)
        {
            cout << "No contact found with name \"" << name << "\".\n";
        }
        else
        {
            cout << "\nTotal matches found: " << count << endl;
        }
    }

    void deleteContact(const string &name)
    {
        if (head == nullptr)
        {
            cout << "Contact list is empty.\n";
            return;
        }

        int totalMatches = countContactsByName(name);

        if (totalMatches == 0)
        {
            cout << "Contact not found.\n";
            return;
        }

        if (totalMatches == 1)
        {
            Node *temp = head;
            Node *prev = nullptr;

            while (temp != nullptr)
            {
                if (temp->data.name == name)
                {
                    if (prev == nullptr)
                    {
                        head = temp->next;
                    }
                    else
                    {
                        prev->next = temp->next;
                    }

                    delete temp;
                    cout << "Contact deleted successfully.\n";
                    return;
                }

                prev = temp;
                temp = temp->next;
            }
        }

        cout << "\nMultiple contacts found with the name \""
             << name << "\":\n";

        Node *temp = head;
        int matchNumber = 1;

        while (temp != nullptr)
        {
            if (temp->data.name == name)
            {
                cout << "\n"
                     << matchNumber << ".\n";
                displayContact(temp->data);
                matchNumber++;
            }

            temp = temp->next;
        }

        int choice;

        cout << "\nEnter contact number to delete: ";
        cin >> choice;

        if (cin.fail() || choice < 1 || choice > totalMatches)
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid choice.\n";
            return;
        }

        cin.ignore(10000, '\n');

        temp = head;
        Node *prev = nullptr;

        matchNumber = 0;

        while (temp != nullptr)
        {
            if (temp->data.name == name)
            {
                matchNumber++;

                if (matchNumber == choice)
                {
                    if (prev == nullptr)
                    {
                        head = temp->next;
                    }
                    else
                    {
                        prev->next = temp->next;
                    }

                    delete temp;
                    cout << "Contact deleted successfully.\n";
                    return;
                }
            }

            prev = temp;
            temp = temp->next;
        }
    }

    void updateContact(const string &name)
    {
        if (head == nullptr)
        {
            cout << "Contact list is empty.\n";
            return;
        }

        int totalMatches = countContactsByName(name);

        if (totalMatches == 0)
        {
            cout << "Contact not found.\n";
            return;
        }

        Node *selected = nullptr;

        if (totalMatches == 1)
        {
            Node *temp = head;

            while (temp != nullptr)
            {
                if (temp->data.name == name)
                {
                    selected = temp;
                    break;
                }

                temp = temp->next;
            }
        }
        else
        {
            cout << "\nMultiple contacts found:\n";

            Node *temp = head;
            int number = 1;

            while (temp != nullptr)
            {
                if (temp->data.name == name)
                {
                    cout << "\n"
                         << number << ".\n";
                    displayContact(temp->data);
                    number++;
                }

                temp = temp->next;
            }

            int choice;

            cout << "\nSelect contact to update: ";
            cin >> choice;

            if (cin.fail() || choice < 1 || choice > totalMatches)
            {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Invalid choice.\n";
                return;
            }

            cin.ignore(10000, '\n');

            temp = head;
            number = 0;

            while (temp != nullptr)
            {
                if (temp->data.name == name)
                {
                    number++;

                    if (number == choice)
                    {
                        selected = temp;
                        break;
                    }
                }

                temp = temp->next;
            }
        }

        Contact updated;

        do
        {
            cout << "Enter New Name: ";
            getline(cin, updated.name);
        } while (!isValidName(updated.name));

        while (true)
        {
            cout << "Enter New Phone: ";
            getline(cin, updated.phone);

            if (!isValidPhone(updated.phone))
                continue;

            if (hasDuplicatePhone(updated.phone, selected))
            {
                cout << "Another contact already uses this phone number.\n";
                continue;
            }

            break;
        }

        while (true)
        {
            cout << "Enter New Email: ";
            getline(cin, updated.email);

            if (!isValidEmail(updated.email))
                continue;

            if (hasDuplicateEmail(updated.email, selected))
            {
                cout << "Another contact already uses this email.\n";
                continue;
            }

            break;
        }

        Node *temp = head;
        Node *prev = nullptr;

        while (temp != selected)
        {
            prev = temp;
            temp = temp->next;
        }

        if (prev == nullptr)
        {
            head = selected->next;
        }
        else
        {
            prev->next = selected->next;
        }

        selected->data = updated;

        if (head == nullptr ||
            selected->data.name < head->data.name)
        {
            selected->next = head;
            head = selected;
        }
        else
        {
            temp = head;

            while (temp->next != nullptr &&
                   temp->next->data.name <= selected->data.name)
            {
                temp = temp->next;
            }

            selected->next = temp->next;
            temp->next = selected;
        }

        cout << "Contact updated successfully.\n";
    }

    void reverseList()
    {
        if (head == nullptr)
        {
            cout << "Contact list is empty.\n";
            return;
        }

        Node *prev = nullptr;
        Node *current = head;
        Node *nextNode = nullptr;

        while (current != nullptr)
        {
            nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        }

        head = prev;

        cout << "Contact list reversed successfully.\n";
    }

    ~ContactList()
    {
        Node *temp;

        while (head != nullptr)
        {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main()
{
    ContactList contactList;
    int choice;

    do
    {
        cout << "CONTACT MANAGEMENT SYSTEM";
        cout << "1. Add Contact\n";
        cout << "2. Display All Contacts\n";
        cout << "3. Search Contact\n";
        cout << "4. Update Contact\n";
        cout << "5. Delete Contact\n";
        cout << "6. Reverse Contact List\n";
        cout << "0. Exit\n";
        cout << "=====================================\n";
        cout << "Enter Choice: ";

        if (!(cin >> choice))
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input. Enter a number.\n";
            continue;
        }

        cin.ignore(10000, '\n');

        switch (choice)
        {
        case 1:
            contactList.addContact();
            break;
        case 2:
            contactList.displayAllContacts();
            break;
        case 3:
        {
            string name;
            cout << "Enter name to search: ";
            getline(cin, name);
            contactList.search(name);
            break;
        }
        case 4:
        {
            string name;
            cout << "Enter name to update: ";
            getline(cin, name);
            contactList.updateContact(name);
            break;
        }
        case 5:
        {
            string name;
            cout << "Enter name to delete: ";
            getline(cin, name);
            contactList.deleteContact(name);
            break;
        }
        case 6:
            contactList.reverseList();
            break;
        case 0:
            cout << "Exiting Contact Management System...\n";
            break;
        default:
            cout << "Invalid choice. Enter a number between 0 and 6.\n";
        }

    } while (choice != 0);

    return 0;
}
