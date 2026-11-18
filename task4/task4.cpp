#include <iostream>
#include <iomanip>
using namespace std;

class Money {
    long long paise;

public:
    Money(long long r = 0, int p = 0) {
        paise = r * 100 + p;
    }

    Money operator+(Money m) {
        return Money(0, paise + m.paise);
    }

    Money operator-(Money m) {
        return Money(0, paise - m.paise);
    }

    Money& operator+=(Money m) {
        paise += m.paise;
        return *this;
    }

    bool operator==(Money m) {
        return paise == m.paise;
    }

    bool operator<(Money m) {
        return paise < m.paise;
    }

    friend ostream& operator<<(ostream& out, Money m) {
        long long value = m.paise;

        if (value < 0) {
            out << "-Rs ";
            value = -value;
        } else {
            out << "Rs ";
        }

        out << value / 100 << "."
            << setw(2) << setfill('0') << value % 100;

        return out;
    }
};

int main() {
    Money a(120, 75);
    Money b(79, 25);

    Money c = a + b;

    cout << c << endl;
    cout << boolalpha << (c == Money(200)) << endl;

    Money x(0, 75);
    Money y(0, 50);

    cout << x + y << endl;

    return 0;
}
