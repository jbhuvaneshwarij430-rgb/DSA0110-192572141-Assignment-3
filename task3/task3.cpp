#include <iostream>
using namespace std;

class Auditorium {
    int rows, seats;
    char** map;

public:
    Auditorium(int r, int s) : rows(r), seats(s) {
        map = new char*[rows];

        for (int i = 0; i < rows; i++) {
            map[i] = new char[seats];

            for (int j = 0; j < seats; j++)
                map[i][j] = 'O';
        }

        cout << "Auditorium created" << endl;
    }

    void book(int r, int s) {
        if (r >= 0 && r < rows && s >= 0 && s < seats)
            map[r][s] = 'X';
    }

    void cancel(int r, int s) {
        if (r >= 0 && r < rows && s >= 0 && s < seats)
            map[r][s] = 'O';
    }

    void display() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < seats; j++)
                cout << map[i][j] << " ";
            cout << endl;
        }
    }

    ~Auditorium() {
        for (int i = 0; i < rows; i++)
            delete[] map[i];

        delete[] map;

        cout << "Auditorium closed" << endl;
    }
};

int main() {
    Auditorium a(2, 3);

    a.book(0, 1);
    a.book(1, 2);

    cout << "Seat Map:" << endl;
    a.display();

    a.cancel(0, 1);

    cout << "After Cancellation:" << endl;
    a.display();

    Auditorium* b = new Auditorium(1, 2);
    b->book(0, 0);
    b->display();
    delete b;

    return 0;
}

