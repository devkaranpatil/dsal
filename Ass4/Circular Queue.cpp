#include <iostream>
using namespace std;

class Array
{
private:
    int *arr;
    int size;
    int front = -1;
    int rear = -1;

    int isEmpty()
    {
        if (front == -1)
        {
            return 1;
        }
        return 0;
    }
    int isFull()
    {
    }

public:
    Array(int s)
    {
        size = s;
        arr = new int[size];
    }
    void enqueue(int value)
    {
        if (rear == size - 1)
        {
            cout << "Queue is full" << endl;
        }
        else
        {
            if (front == -1)
            {
                front = 0;
            }
            rear++;
            arr[rear] = value;
            cout << "Value inserted at position " << rear + 1 << endl;
        }
    }
    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
        }
        else
        {
            int value = arr[front];
            front++;
            cout << "Value removed from position" << front + 1 << endl;
        }
    }
    void front1()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
        }
        else
        {
            cout << " The front value is " << arr[front] << endl;
        }
    }
    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
        }
        else
        {
            cout << "The values in the queue are: ";
            for (int i = front; i <= rear; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

struct Node
{
    int data;
    Node *next;

    Node(int value)
    {
        data = value;
        next = NULL;
    }
};

class LinkedListQueue
{
private:
    Node *front;
    Node *rear;

public:
    LinkedListQueue()
    {
        front = NULL;
        rear = NULL;
    }

    bool isEmpty()
    {
        return front == NULL;
    }

    void enqueue(int value)
    {
        Node *newNode = new Node(value);

        if (isEmpty())
        {
            front = rear = newNode;
            cout << "Value inserted at the front of the queue" << endl;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
            cout << "Value inserted at the rear of the queue" << endl;
        }
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
        }
        else
        {
            Node *temp = front;
            cout << "Value removed: " << front->data << endl;
            front = front->next;

            if (front == NULL)
            {
                rear = NULL;
            }

            delete temp;
        }
    }

    void front1()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
        }
        else
        {
            cout << "The front value is " << front->data << endl;
        }
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
        }
        else
        {
            Node *temp = front;
            cout << "The values in the queue are: ";
            while (temp != NULL)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};

int main()
{
    int index;
    int value;
    int size;
    cout << "Enter the size of the array queue: ";
    cin >> size;
    Array queue(size);
    LinkedListQueue linkedQueue;

    do
    {
        cout << "\nQueue Program\n"
             << "\nArray Queue:"
             << "\nEnter 1 for Adding Element In The Queue"
             << "\nEnter 2 for Removing Element From The Queue"
             << "\nEnter 3 for Displaying the Front Element"
             << "\nEnter 4 for Displaying All Elements In The Queue"
             << "\n\nLinked List Queue:"
             << "\nEnter 5 for Adding Element In The Queue"
             << "\nEnter 6 for Removing Element From The Queue"
             << "\nEnter 7 for Displaying the Front Element"
             << "\nEnter 8 for Displaying All Elements In The Queue"
             << "\nEnter 0 for Exit\n";

        cout << "Choice: ";
        cin >> index;
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
            cout << "Enter value: ";
            cin >> value;
            queue.enqueue(value);
            break;

        case 2:
            queue.dequeue();
            break;

        case 3:
            queue.front1();
            break;

        case 4:
            queue.display();
            break;

        case 5:
            cout << "Enter value: ";
            cin >> value;
            linkedQueue.enqueue(value);
            break;

        case 6:
            linkedQueue.dequeue();
            break;

        case 7:
            linkedQueue.front1();
            break;

        case 8:
            linkedQueue.display();
            break;

        default:
            cout << "Invalid input.\n";
        }

        cout << endl;

    } while (index != 0);

    return 0;
}
