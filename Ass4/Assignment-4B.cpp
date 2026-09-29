#include <iostream>
#include <string>
using namespace std;

struct Patients
{
    string name;
    string symptoms;
    int appointment_number;
    string gender;
    int priority;
};

class HospitalQueue
{
private:
    Patients *queue;
    int size;
    int front;
    int rear;

    bool isEmpty()
    {
        return front == -1 || front > rear;
    }

    bool isFull()
    {
        return rear == size - 1;
    }

public:
    HospitalQueue(int s)
    {
        size = s;
        queue = new Patients[s];
        front = -1;
        rear = -1;
    }

    void insertionSort()
    {
        if (isEmpty())
            return;

        for (int i = front + 1; i <= rear; i++)
        {
            Patients key = queue[i];
            int j = i - 1;

            while (j >= front && queue[j].priority > key.priority)
            {
                queue[j + 1] = queue[j];
                j--;
            }

            queue[j + 1] = key;
        }
    }

    bool enqueue()
    {
        if (isFull())
        {
            cout << "\nQueue is full!\n";
            return false;
        }

        Patients p;

        cin.ignore();

        cout << "\nEnter patient name: ";
        getline(cin, p.name);

        cout << "Enter symptoms: ";
        getline(cin, p.symptoms);

        cout << "Enter appointment number: ";
        cin >> p.appointment_number;

        cin.ignore();

        cout << "Enter gender: ";
        getline(cin, p.gender);

        cout << "Enter priority (1 = highest): ";
        cin >> p.priority;

        if (front == -1)
        {
            front = 0;
        }

        rear++;

        queue[rear] = p;

        insertionSort();

        cout << "\nPatient added to queue successfully!\n";

        return true;
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "\nQueue is empty!\n";
            return;
        }

        cout << "\nPatient removed:\n";
        cout << "Name: " << queue[front].name << endl;
        cout << "Appointment Number: "
             << queue[front].appointment_number << endl;

        front++;

        if (front > rear)
        {
            front = -1;
            rear = -1;
        }
    }

    void front1()
    {
        if (isEmpty())
        {
            cout << "\nQueue is empty!\n";
            return;
        }

        cout << "\n--- First Patient ---\n";
        cout << "Appointment Number: "
             << queue[front].appointment_number << endl;
        cout << "Name: "
             << queue[front].name << endl;
        cout << "Gender: "
             << queue[front].gender << endl;
        cout << "Symptoms: "
             << queue[front].symptoms << endl;
        cout << "Priority: "
             << queue[front].priority << endl;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "\nQueue is empty!\n";
            return;
        }

        cout << "\n========== PATIENT QUEUE ==========\n";

        for (int i = front; i <= rear; i++)
        {
            cout << "\nPatient " << i - front + 1 << endl;
            cout << "Appointment Number: "
                 << queue[i].appointment_number << endl;
            cout << "Name: "
                 << queue[i].name << endl;
            cout << "Gender: "
                 << queue[i].gender << endl;
            cout << "Symptoms: "
                 << queue[i].symptoms << endl;
            cout << "Priority: "
                 << queue[i].priority << endl;
        }

        cout << "===================================\n";
    }
};

int main()
{
    int size;

    cout << "Enter maximum number of patients: ";
    cin >> size;

    HospitalQueue hq(size);

    int choice;

    do
    {
        cout << "\n\nHospital Queue\n";
        cout << "1. Add Patient\n";
        cout << "2. Remove Patient\n";
        cout << "3. View First Patient\n";
        cout << "4. Display All Patients\n";
        cout << "5. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            hq.enqueue();
            break;

        case 2:
            hq.dequeue();
            break;

        case 3:
            hq.front1();
            break;

        case 4:
            hq.display();
            break;

        case 5:
            cout << "\nExiting program...\n";
            break;

        default:
            cout << "\nInvalid choice! Please try again.\n";
        }

    } while (choice != 5);

    return 0;
}
