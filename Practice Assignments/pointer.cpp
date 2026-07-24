#include <iostream>
#include <string>

using namespace std;

class StudentMarks
{
private:
    string name;
    int rollNumber;
    int marks[5];
    bool hasData;
    static int currentRollNumber;

public:
    StudentMarks()
    {
        rollNumber = 0;
        for (int i = 0; i < 5; ++i)
        {
            marks[i] = 0;
        }
        hasData = false;
    }

    void inputStudentData()
    {
        while (true)
        {
            cout << "\nEnter Student Name: ";
            getline(cin, name);

            bool valid = true;
            if (name.empty())
            {
                valid = false;
            }
            else
            {
                for (char ch : name)
                {
                    bool isLetter = (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z');
                    if (ch != ' ' && !isLetter)
                    {
                        valid = false;
                        break;
                    }
                }
            }

            if (!valid)
            {
                cout << "Invalid name. Only letters and spaces are allowed. Retype the name.\n";
                continue;
            }

            break;
        }

        rollNumber = currentRollNumber++;
        cout << "Assigned Roll Number: " << rollNumber << "\n";
        cout << "Enter marks for 5 subjects:\n";
        for (int i = 0; i < 5; ++i)
        {
            cout << "Subject " << (i + 1) << ": ";
            cin >> marks[i];
        }
        cin.ignore(1000, '\n');
        hasData = true;
    }

    void displayStudentData()
    {
        if (!hasData)
        {
            cout << "No student data available. Please add a student first.\n";
            return;
        }

        cout << "Student Name: " << name << "\n";
        cout << "Roll Number: " << rollNumber << "\n";
        cout << "Average Marks: " << calculateAverage() << "\n";
    }

    double calculateAverage()
    {
        double sum = 0;
        for (int i = 0; i < 5; ++i)
        {
            sum += marks[i];
        }
        return sum / 5;
    }
};

int StudentMarks::currentRollNumber = 1;

void displayAllStudents(StudentMarks *students, int count)
{
    if (count == 0)
    {
        cout << "No student data available. Please add a student first.\n";
        return;
    }

    for (int i = 0; i < count; ++i)
    {
        cout << "\nStudent " << (i + 1) << "\n";
        students[i].displayStudentData();
    }
}

int main()
{
    int capacity = 5;
    StudentMarks *students = new StudentMarks[capacity];
    int count = 0;

    int choice;
    while (true)
    {
        cout << "\nStudent Menu\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(1000, '\n');

        if (choice == 1)
        {
            if (count >= 5)
            {
                cout << "You can add only 5 students.\n";
                continue;
            }

            students[count].inputStudentData();
            ++count;
        }
        else if (choice == 2)
        {
            displayAllStudents(students, count);
        }
        else if (choice == 3)
        {
            cout << "Exiting program.\n";
            break;
        }
        else
        {
            cout << "Invalid choice. Please try again.\n";
        }
    }

    delete[] students;
    return 0;
}