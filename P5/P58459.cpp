// program that prints if a date is valid or not

#include <iostream>
using namespace std;

bool is_leap_year(int year) {
    return (year % 4 == 0 and (year % 100 != 0 or year % 400 == 0));
}

bool is_valid_date(int d, int m, int y) {
    if (m >= 1 and m <= 12) { // month
        if (d >= 1 and d <= 31) {
            if (m == 1 or m == 3 or m == 5 or m == 7 or m == 8 or m == 10 or m == 12) {
                return true;
            }
            else if (m == 4 or m == 6 or m == 9 or m == 11) {
                if (d <= 30) return true;
                else return false;
            }
            else {
                if (is_leap_year(y) and d <= 29) return true;
                else if (d <= 28) return true;
                else return false;
            }
        }
        else return false;
    }
    else return false;
}

int main () {
    int day, month, year;
    cin >> day >> month >> year;
    if (is_valid_date(day, month, year)) cout << "true" << endl;
    else cout << "false" << endl;
}