#include <iostream>
#include <string>
using namespace std;

class StudentMarks
{
private:
    string name;
    int rollNumber;
    int marks[5];

public:
    void inputStudentData()
    {
        cout << "\nEnter Student Name: ";
        getline(cin, name);

        cout << "Enter Roll Number: ";
        cin >> rollNumber;
        cout << "Enter marks for 5 subjects:\n";
        for (int i = 0; i < 5; ++i)
        {
            cout << "Subject " << (i + 1) << ": ";
            cin >> marks[i];
        }
        cin.ignore();
    }
    void displayStudentData()
    {
        cout << "Student Name: " << name << "\n";
        cout << "Roll Number: " << rollNumber << "\n";
        cout << "Average Marks:" << calculateAverage() << "\n";
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
        cout << "\nDisplaying data for student" << (i + 1) << ":\n";
        student[i].displayStudentData();
        cout << "\n";
    }
}