#include <iostream>
#include <string>

using namespace std;

struct Book
{
    int id;
    string title;
    string author;
    double price;
};

class BookManagement
{
private:
    Book books[100];
    int count;

public:
    BookManagement() : count(0) {}

    bool addBook(int id, const string &title, const string &author, double price)
    {
        if (count == 100)
        {
            cout << "Book storage is full.\n";
            return false;
        }

        int insertAt = 0;
        while (insertAt < count && books[insertAt].id < id)
            ++insertAt;

        if (insertAt < count && books[insertAt].id == id)
        {
            cout << "A book with ID " << id << " already exists.\n";
            return false;
        }

        for (int i = count; i > insertAt; --i)
            books[i] = books[i - 1];

        books[insertAt] = {id, title, author, price};
        ++count;
        cout << "Book added successfully.\n";
        return true;
    }

    int binarySearchById(int id) const
    {
        int low = 0;
        int high = count - 1;

        while (low <= high)
        {
            int middle = low + (high - low) / 2;

            if (books[middle].id == id)
                return middle;
            if (books[middle].id < id)
                low = middle + 1;
            else
                high = middle - 1;
        }
        return -1;
    }

    void searchBookById(int id) const
    {
        int index = binarySearchById(id);
        if (index == -1)
            cout << "Book with ID " << id << " was not found.\n";
        else
        {
            cout << "Book found at position " << index + 1 << ":\n";
            displayBook(books[index]);
        }
    }

    void displayBooks() const
    {
        if (count == 0)
        {
            cout << "No books available.\n";
            return;
        }

        cout << "\nBOOKS\n";
        for (int i = 0; i < count; ++i)
            displayBook(books[i]);
    }

    void displayBook(const Book &book) const
    {
        cout << "ID: " << book.id << "\n"
             << "Title: " << book.title << "\n"
             << "Author: " << book.author << "\n"
             << "Price: " << book.price << "\n";
    }
};

int main()
{
    BookManagement library;
    int choice;

    do
    {
        cout << "\nBOOK MANAGEMENT SYSTEM\n"
             << "1. Add book\n"
             << "2. Display all books\n"
             << "3. Search book by ID\n"
             << "0. Exit\n"
             << "Enter your choice: ";

        if (!(cin >> choice))
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Please enter a number.\n";
            continue;
        }
        cin.ignore(10000, '\n');

        switch (choice)
        {
        case 1:
        {
            int id;
            double price;
            string title, author;
            cout << "Enter book ID: ";
            if (!(cin >> id))
            {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Invalid book ID. Book was not added.\n";
                continue;
            }
            cin.ignore(10000, '\n');
            cout << "Enter title: ";
            getline(cin, title);
            cout << "Enter author: ";
            getline(cin, author);
            cout << "Enter price: ";
            if (!(cin >> price) || price < 0)
            {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Invalid price. Book was not added.\n";
            }
            else
            {
                cin.ignore(10000, '\n');
                library.addBook(id, title, author, price);
            }
            break;
        }
        case 2:
            library.displayBooks();
            break;
        case 3:
        {
            int id;
            cout << "Enter book ID to search: ";
            if (cin >> id)
                library.searchBookById(id);
            else
            {
                cin.clear();
                cout << "Invalid book ID.\n";
            }
            cin.ignore(10000, '\n');
            break;
        }
        case 0:
            break;
        default:
            cout << "Invalid choice.\n";
            break;
        }
    } while (choice != 0);

    return 0;
}
