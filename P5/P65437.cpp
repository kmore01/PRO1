// program that swap the value of two parameters

#include <iostream>
using namespace std;

// function that swap values
// Precondition: integer
// Postcondition: integer
void swap2(int& a, int& b) {
    int c = a;
    a = b;
    b = c;
}

int main () {
    int x, y;
    cin >> x >> y;
    swap2(x, y);
    cout << x << ' ' << y << endl;
}