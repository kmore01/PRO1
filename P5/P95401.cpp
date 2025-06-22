// program that prints if a years it's a leap year

#include <iostream>
using namespace std;

// function that calculates if a years it's leap
// Precondition: 1800 < year < 9999
// Postcondition: boolean
bool is_leap_year(int year) {
    return (year % 4 == 0 and (year % 100 != 0 or year % 400 == 0));
}

int main () {
    int year; // 1800 < integer < 9999
    cin >> year;
    if (is_leap_year(year)) cout << "true" << endl;
    else cout << "false" << endl;
}