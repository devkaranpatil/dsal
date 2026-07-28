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
    void mergelinkedlist(list *firstList, list *secondlist)
    {
        head = firstList->head;
        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = secondlist->head;
        displayAllElements();
    }
};

int main()
{
    int index = 1;
    int data;
    list linkList1;
    list linkList2;
    list mergedlist;

    do
    {
        cout << "\nEfficient Data Management Using Linked Lists\n"
             << "\nEnter 1 for Adding Element At the End For List 1"
             << "\nEnter 2 for Adding Element At the End For List 2"
             << "\nEnter 3 for Displaying All Elements for List 1"
             << "\nEnter 4 for Displaying All Elements for List 2"
             << "\nEnter 5 for Merging and Displaying Merged List"
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
            linkList1.insertAtEnd(data);
            cout << "Element Added";
            break;

        case 2:
            cout << "Enter data: ";
            cin >> data;
            linkList2.insertAtEnd(data);
            cout << "Element Added";
            break;

        case 3:
            linkList1.displayAllElements();
            break;

        case 4:
            linkList2.displayAllElements();
            break;

        case 5:
            mergedlist.mergelinkedlist(&linkList1, &linkList2);
            break;

        default:
            cout << "Invalid input.\n";
        }

        cout << endl;

    } while (index != 0);

    return 0;
}