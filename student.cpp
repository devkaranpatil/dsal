#include <iostream>
#include <string>
#include <cctype>

using namespace std;

class StudentMarks
{
private:
    string name;
    int rollNumber;
    int marks[5];
    static int nextRollNumber;

public:
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

        rollNumber = nextRollNumber++;
        cout << "Assigned Roll Number: " << rollNumber << "\n";
        cout << "Enter marks for 5 subjects:\n";
        for (int i = 0; i < 5; ++i)
        {
            cout << "Subject " << (i + 1) << ": ";
            cin >> marks[i];
        }
        cin.ignore(1000, '\n');
    }
    void displayStudentData()
    {
        cout << "Student Name: " << name << "\n";
        cout << "Roll Number: " << rollNumber << "\n";
        cout << "Average Marks: " << calculateAverage() << "\n";
    }
    double calculateAverage()
    {
        double sum = 0;
        for (int i = 0; i < 5; i++)
        {
            sum += marks[i];
        }
        return sum / 5;
    }
};

int StudentMarks::nextRollNumber = 1;

int main()
{
    StudentMarks student[5];
    for (int i = 0; i < 5; i++)
    {
        cout << "Enter data for student " << (i + 1) << ":\n";
        student[i].inputStudentData();
    }
    for (int i = 0; i < 5; i++)
    {
        cout << "\nDisplaying data for student " << (i + 1) << ":\n";
        student[i].displayStudentData();
        cout << "\n";
    }
}