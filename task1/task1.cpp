
#include <iostream>
#include <string>
using namespace std;

class Book {
    string title;
    int copies;

public:
    Book() : Book("Unknown", 0) {}

    Book(string t) : Book(t, 1) {}

    Book(string t, int c)
        : title(t), copies(c < 0 ? 0 : c) {}

    void display() {
        cout << "Title: " << title
             << ", Copies: " << copies << endl;
    }
};

int main() {
    Book b1;
    Book b2("C++ Programming");
    Book b3("Python", 5);

    b1.display();
    b2.display();
    b3.display();

    return 0;
}

