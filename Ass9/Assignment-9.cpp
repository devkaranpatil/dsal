#include <fstream>
#include <iostream>
#include <string>

using namespace std;

const char *FILE_NAME = "students.txt";

struct Student
{
    int id;
    string name;
};

bool readStudent(ifstream &file, Student &student)
{
    return static_cast<bool>(file >> student.id >> ws && getline(file, student.name));
}

void discardLine()
{
    string unused;
    getline(cin, unused);
}

bool idExists(int id)
{
    ifstream file(FILE_NAME);
    Student student;
    while (readStudent(file, student))
    {
        if (student.id == id)
            return true;
    }
    return false;
}

void addRecord()
{
    Student student;
    cout << "Enter student ID: ";
    if (!(cin >> student.id))
    {
        cout << "Invalid ID.\n";
        cin.clear();
        discardLine();
        return;
    }
    if (idExists(student.id))
    {
        cout << "A record with that ID already exists.\n";
        return;
    }
    cout << "Enter student name: ";
    getline(cin >> ws, student.name);
    if (student.name.empty())
    {
        cout << "Name cannot be empty.\n";
        return;
    }

    ofstream file(FILE_NAME, ios::app);
    if (!file)
    {
        cout << "Could not open the records file.\n";
        return;
    }
    file << student.id << '\n'
         << student.name << '\n';
    cout << "Record appended.\n";
}

void displayRecords()
{
    ifstream file(FILE_NAME);
    Student student;
    bool found = false;
    cout << "\nStudent records (sequential order):\n";
    while (readStudent(file, student))
    {
        cout << "ID: " << student.id << " | Name: " << student.name << '\n';
        found = true;
    }
    if (!found)
        cout << "No records found.\n";
}

void searchRecord()
{
    int id;
    cout << "Enter student ID to search: ";
    if (!(cin >> id))
    {
        cout << "Invalid ID.\n";
        cin.clear();
        discardLine();
        return;
    }

    ifstream file(FILE_NAME);
    Student student;
    while (readStudent(file, student))
    {
        if (student.id == id)
        {
            cout << "Record found: ID: " << student.id << " | Name: " << student.name << '\n';
            return;
        }
    }
    cout << "Record not found.\n";
}

void deleteRecord()
{
    int id;
    cout << "Enter student ID to delete: ";
    if (!(cin >> id))
    {
        cout << "Invalid ID.\n";
        cin.clear();
        discardLine();
        return;
    }

    ifstream input(FILE_NAME);
    if (!input)
    {
        cout << "No records file exists.\n";
        return;
    }
    const char *tempName = "students.tmp";
    ofstream output(tempName);
    if (!output)
    {
        cout << "Could not create a temporary file.\n";
        return;
    }

    Student student;
    bool deleted = false;
    while (readStudent(input, student))
    {
        if (student.id == id && !deleted)
        {
            deleted = true;
            continue;
        }
        output << student.id << '\n'
               << student.name << '\n';
    }
    input.close();
    output.close();

    if (!deleted)
    {
        cout << "Record not found.\n";
        return;
    }
    // Copy the rewritten records back using standard C++ streams.
    ifstream rewritten(tempName);
    ofstream original(FILE_NAME, ios::trunc);
    if (!rewritten || !original)
    {
        cout << "Could not update the records file.\n";
        return;
    }
    string line;
    while (getline(rewritten, line))
        original << line << '\n';
    cout << "Record deleted.\n";
}

int main()
{
    int choice;
    do
    {
        cout << "\n--- Sequential Student File ---\n"
             << "1. Append record\n"
             << "2. Display all records\n"
             << "3. Search record by ID\n"
             << "4. Delete record by ID\n"
             << "5. Exit\n"
             << "Enter choice: ";
        if (!(cin >> choice))
        {
            cout << "Invalid choice.\n";
            cin.clear();
            discardLine();
            continue;
        }

        switch (choice)
        {
        case 1:
            addRecord();
            break;
        case 2:
            displayRecords();
            break;
        case 3:
            searchRecord();
            break;
        case 4:
            deleteRecord();
            break;
        case 5:
            cout << "Exiting.\n";
            break;
        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != 5);

    return 0;
}
