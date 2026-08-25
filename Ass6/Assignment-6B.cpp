#include <iostream>
#include <string>

using namespace std;

struct Student
{
    string name;
    int rollNo;
    string branch;
    float marks;
};

class StudentManager
{
private:
    Student students[100];
    int count;

    void displayStudents(const Student list[]) const
    {
        if (count == 0)
        {
            cout << "No student records available.\n";
            return;
        }

        cout << "Roll No\tName\t\tBranch\t\tMarks\n";
        cout << "------------------------------------------------------------\n";

        for (int i = 0; i < count; i++)
        {
            cout << list[i].rollNo << '\t' << list[i].name << "\t\t"
                 << list[i].branch << "\t\t" << list[i].marks << '\n';
        }
    }

    void copyRecords(Student destination[]) const
    {
        for (int i = 0; i < count; i++)
            destination[i] = students[i];
    }

public:
    StudentManager() : count(0) {}

    void inputStudents()
    {
        cout << "Enter number of students";
        cin >> count;

        while (cin.fail() || count < 1 || count > 100)
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Enter a number between 1 and 100";
            cin >> count;
        }

        cin.ignore(10000, '\n');
        for (int i = 0; i < count; i++)
        {
            cout << "\nStudent " << i + 1 << '\n';
            cout << "Name: ";
            getline(cin, students[i].name);
            cout << "Roll number: ";
            cin >> students[i].rollNo;
            cout << "Branch: ";
            cin.ignore(10000, '\n');
            getline(cin, students[i].branch);
            cout << "Marks: ";
            cin >> students[i].marks;
            cin.ignore(10000, '\n');
        }
    }

    void displayOriginalRecords() const
    {
        displayStudents(students);
    }

    void insertionSortAscending() const
    {
        Student sorted[100];
        copyRecords(sorted);

        for (int i = 1; i < count; i++)
        {
            Student key = sorted[i];
            int j = i - 1;
            while (j >= 0 && sorted[j].marks > key.marks)
            {
                sorted[j + 1] = sorted[j];
                j--;
            }
            sorted[j + 1] = key;
        }

        cout << "\nStudents sorted by marks in ascending order (Insertion Sort):\n";
        displayStudents(sorted);
    }

    void bubbleSortDescending() const
    {
        Student sorted[100];
        copyRecords(sorted);

        for (int i = 0; i < count - 1; i++)
        {
            bool swapped = false;
            for (int j = 0; j < count - i - 1; j++)
            {
                if (sorted[j].marks < sorted[j + 1].marks)
                {
                    Student temp = sorted[j];
                    sorted[j] = sorted[j + 1];
                    sorted[j + 1] = temp;
                    swapped = true;
                }
            }
            if (!swapped)
                break;
        }

        cout << "\nStudents sorted by marks in descending order (Bubble Sort):\n";
        displayStudents(sorted);
    }
};

int main()
{
    StudentManager manager;
    int choice;

    do
    {
        cout << "\n--- Student Marks Management System ---\n";
        cout << "1. Enter student records\n";
        cout << "2. Display student records\n";
        cout << "3. Sort marks ascending (Insertion Sort)\n";
        cout << "4. Sort marks descending (Bubble Sort)\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(10000, '\n');
            choice = 0;
        }

        switch (choice)
        {
        case 1:
            manager.inputStudents();
            break;
        case 2:
            manager.displayOriginalRecords();
            break;
        case 3:
            manager.insertionSortAscending();
            break;
        case 4:
            manager.bubbleSortDescending();
            break;
        case 5:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
