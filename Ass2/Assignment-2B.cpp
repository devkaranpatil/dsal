#include <iostream>
using namespace std;

class Song
{
public:
    string songname;
    string artist;
    float duration;

    Song() {}
    Song(string sname, string art, float dur)
    {
        songname = sname;
        artist = art;
        duration = dur;
    }
};

class Node
{
public:
    Song data;
    Node *next;
    Node *prev;

    Node(const Song &value)
    {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};

class MusicPlaylist
{
public:
    Node *head = nullptr;
};