#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

class StackList
{
    Node *top;

public:
    StackList() { top = nullptr; }

    void push(int x)
    {

        Node *newNode = new (nothrow) Node(x);
        if (newNode == nullptr)
        {
            cout << "Stack Overflow (Heap full)\n";
            return;
        }
        newNode->next = top;
        top = newNode;
        cout << x << " pushed into stack\n";
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow\n";
            return;
        }
        Node *temp = top;
        cout << temp->data << " popped from stack\n";
        top = top->next;
        delete temp;
    }

    int peek()
    {
        if (isEmpty())
        {
            cout << "Stack is Empty\n";
            return -1;
        }
        return top->data;
    }

    bool isEmpty() { return top == nullptr; }

    bool isFull()
    {
        Node *test = new (nothrow) Node(0);
        if (test == nullptr)
            return true;
        delete test;
        return false;
    }
};

int main()
{

    StackList s;
    int choice, value;

    do
    {
        cout << "\n--- Stack Menu (Linked List) ---\n";
        cout << "1. Push\n2. Pop\n3. Peek\n4. Check Empty\n5.Check Full\n6.Exit\n ";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to push: ";
            cin >> value;
            s.push(value);
            break;
        case 2:
            s.pop();
            break;
        case 3:

            cout << "Top element: " << s.peek() << endl;
            break;
        case 4:
            cout << (s.isEmpty() ? "Stack is Empty\n" : "Stack is not Empty\n");
            break;
        case 5:
            cout << (s.isFull() ? "Stack is Full\n" : "Stack is not Full\n");
            break;
        case 6:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 6);

    return 0;
}