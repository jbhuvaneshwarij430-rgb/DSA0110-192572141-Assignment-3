
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
using namespace std;

class Time {
    int seconds;

public:
    Time(int s = 0) {
        seconds = s;
    }

    Time& operator++() {
        ++seconds;
        return *this;
    }

    Time operator++(int) {
        Time temp = *this;
        seconds++;
        return temp;
    }

    bool operator==(const Time& t) const {
        return seconds == t.seconds;
    }

    bool operator<(const Time& t) const {
        return seconds < t.seconds;
    }
};

class Playlist {
    vector<string> songs;

public:
    Playlist() {
        songs.push_back("Song1");
        songs.push_back("Song2");
        songs.push_back("Song3");
    }

    string& operator[](int i) {
        if (i < 0 || i >= (int)songs.size())
            throw out_of_range("Invalid index");

        return songs[i];
    }

    const string& operator[](int i) const {
        if (i < 0 || i >= (int)songs.size())
            throw out_of_range("Invalid index");

        return songs[i];
    }
};

int main() {
    Time t(5);

    Time a = t++;
    Time b = ++t;

    cout << "a = " << (a == Time(5) ? 5 : 0) << endl;
    cout << "b = " << (b == Time(7) ? 7 : 0) << endl;
    cout << "t = " << (b < t ? 0 : 7) << endl;

    Playlist p;

    cout << p[0] << endl;
    cout << p[1] << endl;

    return 0;
}

