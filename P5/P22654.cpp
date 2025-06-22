// program that froma quantity of seconds calculates how many hours, minutes and
// seconds represents

#include <iostream>
using namespace std;

// funcion that calculates how many hours, minutes and seconds
// Precondition: natural
// Postcondition: 0 ≤ s < 60 and 0 ≤ m <60.
void decompose(int n, int& h, int& m, int& s) {
    h = n / 3600;
    m = (n % 3600) / 60;
    s = n % 60;
}

int main () {
    int time, hours, minutes, seconds; // natural
    cin >> time;
    decompose(time, hours, minutes, seconds);
    cout << hours << ' ' << minutes << ' ' << seconds << endl;
}