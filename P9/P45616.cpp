/* program that implements some actions on a clock */

#include <iostream>

using namespace std;

struct Clock {
    int h; // hours (0 <= h < 24)
    int m; // minutes (0 <= m < 60)
    int s; // seconds (0 <= s < 60)
};

/* function that returns a clock initialized to midnight */
Clock midnight() {
    /* in order to use it we need to call the struct with a name */
    Clock midnight;
    midnight.s = midnight.m = midnight.h = 0;
    return midnight;
}

/* procedure that increases a second the clock */
void increase(Clock& r) {
    ++r.s;
    if (r.s == 60) {
        r.s = 0;
        if (r.m == 59) {
            r.m = 0;
            if (r.h == 23) r.h = 0;
            else ++r.h;
        }
        else ++r.m;
    }
}

/* procedure that prints the clock */
void print(const Clock& r) {
    cout << r.h / 10 << r.h % 10 << ':';
    cout << r.m / 10 << r.m % 10 << ':';
    cout << r.s / 10 << r.s % 10 << endl;
}

/* int main () {
    Clock hour, min, second;
    cin >> hour.h >> min.m >> second.s;
}
*/