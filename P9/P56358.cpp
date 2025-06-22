/* program that calculates the result of adding ore substracting one second to
a timer */

#include <iostream>

using namespace std;

struct Time {
    int hour, minute, second;
};

/* procedure that returns the clock with one second more and one less */
void one_second(const Time& t, Time& t1, Time& t2) {
    int clock = t.second + t.hour * 3600 + t.minute * 60;
    /* T1 */
    t1.second = clock + 1;
    t1.hour = (t1.second / 3600) % 24;
    t1.minute = (t1.second % 3600) / 60;
    t1.second = t1.second % 60;
    /* T2 */
    t2.second = clock - 1;
    if (t2.second < 0) {
        t2.hour = 23;
        t2.minute = 59;
        t2.second = 59;
    }
    else {
        t2.hour = (t2.second / 3600) % 24;
        t2.minute = (t2.second % 3600) / 60;
        t2.second = t2.second % 60;
    }
    cout << t1.hour << ' ' << t1.minute << ' ' << t1.second << endl;
    cout << t2.hour << ' ' << t2.minute << ' ' << t2.second << endl;
}

int main() {
	Time t, t1, t2;
	int hour, minute, second;
	while (cin >> hour >> minute >> second) {
		t.hour = hour;
		t.minute = minute;
		t.second = second;
		one_second(t, t1, t2);
	}
}
