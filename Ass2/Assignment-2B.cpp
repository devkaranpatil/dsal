#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    string songname;
    string artist;
    Node *next;
    Node *prev;

    Node(const string &name, const string &artistName)
        : songname(name), artist(artistName), next(NULL), prev(NULL)
    {
    }
};

class Playlist
{
public:
    Node *head;
    Node *tail;
    Node *current;

    Playlist()
        : head(NULL), tail(NULL), current(NULL)
    {
    }

    bool isEmpty() const
    {
        return head == NULL;
    }

    void addSong(const string &songname, const string &artist)
    {
        Node *newNode = new Node(songname, artist);
        if (isEmpty())
        {
            head = tail = newNode;
            current = head;
            return;
        }

        Node *temp = head;
        while (temp != NULL && temp->songname < songname)
            temp = temp->next;

        if (temp == head)
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        else if (temp == NULL)
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        else
        {
            newNode->next = temp;
            newNode->prev = temp->prev;
            temp->prev->next = newNode;
            temp->prev = newNode;
        }
        if (current == NULL)
            current = head;
    }

    void display() const
    {
        if (isEmpty())
        {
            cout << "Playlist is empty." << endl;
            return;
        }

        cout << "---- PLAYLIST ----" << endl;
        Node *temp = head;
        int index = 1;
        while (temp != NULL)
        {
            cout << index << ". " << temp->songname << " - " << temp->artist;
            if (temp == current)
                cout << "  <== current";
            cout << endl;
            temp = temp->next;
            index++;
        }
    }

    bool searchByName(const string &songname) const
    {
        Node *temp = head;
        int position = 1;
        while (temp != NULL)
        {
            if (temp->songname == songname)
            {
                cout << "Song found at position " << position << ": " << temp->songname << " - " << temp->artist << endl;
                return true;
            }
            temp = temp->next;
            position++;
        }
        cout << "Song '" << songname << "' not found." << endl;
        return false;
    }

    bool searchByArtist(const string &artist) const
    {
        Node *temp = head;
        int position = 1;
        bool found = false;
        while (temp != NULL)
        {
            if (temp->artist == artist)
            {
                cout << "Found at position " << position << ": " << temp->songname << " - " << temp->artist << endl;
                found = true;
            }
            temp = temp->next;
            position++;
        }
        if (!found)
            cout << "Artist '" << artist << "' not found." << endl;
        return found;
    }

    // Deletes the first song matching `songname`. Returns true if removed.
    bool deleteSong(const string &songname)
    {
        if (isEmpty())
            return false;

        Node *temp = head;
        while (temp != NULL && temp->songname != songname)
            temp = temp->next;

        if (temp == NULL)
            return false;

        if (temp == head)
        {
            head = head->next;
            if (head)
                head->prev = NULL;
            else
                tail = NULL;
        }
        else if (temp == tail)
        {
            tail = tail->prev;
            if (tail)
                tail->next = NULL;
            else
                head = NULL;
        }
        else
        {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
        }

        if (current == temp)
            current = temp->next ? temp->next : temp->prev;

        delete temp;
        return true;
    }

    void nextSong()
    {
        if (isEmpty())
        {
            cout << "Playlist is empty." << endl;
            return;
        }
        if (current == NULL)
            current = head;
        else if (current->next != NULL)
            current = current->next;
        else
        {
            cout << "Already at the last song." << endl;
            return;
        }
        displayCurrentSong();
    }

    void previousSong()
    {
        if (isEmpty())
        {
            cout << "Playlist is empty." << endl;
            return;
        }
        if (current == NULL)
            current = head;
        else if (current->prev != NULL)
            current = current->prev;
        else
        {
            cout << "Already at the first song." << endl;
            return;
        }
        displayCurrentSong();
    }

    void displayCurrentSong() const
    {
        if (isEmpty() || current == NULL)
        {
            cout << "No current song to display." << endl;
            return;
        }
        cout << "Current song: " << current->songname << " - " << current->artist << endl;
    }
};

int main()
{
    Playlist playlist;
    int choice = 0;

    do
    {
        cout << "\n--- MUSIC PLAYLIST MANAGER ---" << endl;
        cout << "1. Add song" << endl;
        cout << "2. Delete song" << endl;
        cout << "3. Display playlist" << endl;
        cout << "4. Search song by name" << endl;
        cout << "5. Search song by artist" << endl;
        cout << "6. Next song" << endl;
        cout << "7. Previous song" << endl;
        cout << "8. Display current song" << endl;
        cout << "9. Exit" << endl;
        cout << "Enter your choice: ";
        if (!(cin >> choice))
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid choice. Please enter a number." << endl;
            continue;
        }
        cin.ignore(10000, '\n');

        switch (choice)
        {
        case 1:
        {
            string name;
            cout << "Enter song name: ";
            getline(cin, name);
            string artist;
            cout << "Enter artist name: ";
            getline(cin, artist);
            playlist.addSong(name, artist);
            cout << "Song added" << endl;
            break;
        }
        case 2:
        {
            string name;
            cout << "Enter song name to delete: ";
            getline(cin, name);
            if (playlist.deleteSong(name))
                cout << "Song deleted: " << name << endl;
            else
                cout << "Song not found: " << name << endl;
            break;
        }
        case 3:
            playlist.display();
            break;
        case 4:
        {
            string name;
            cout << "Enter song name to search: ";
            getline(cin, name);
            playlist.searchByName(name);
            break;
        }
        case 5:
        {
            string artist;
            cout << "Enter artist name to search: ";
            getline(cin, artist);
            playlist.searchByArtist(artist);
            break;
        }
        case 6:
            playlist.nextSong();
            break;
        case 7:
            playlist.previousSong();
            break;
        case 8:
            playlist.displayCurrentSong();
            break;
        case 9:
            cout << "Exiting playlist manager." << endl;
            break;
        default:
            cout << "Invalid choice." << endl;
            break;
        }
    } while (choice != 9);

    return 0;
}
