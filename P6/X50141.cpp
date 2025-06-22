// program that calculates the fatten number

#include <iostream>
using namespace std;

// precondition: 0 < x < 10^9
// function that returns the result of fattening x
int fatten(int x) {
    if (x < 10) return x; // case base
    else { // general base
        int y = fatten(x / 10);
        int y_max = y % 10;
	    int x_max = x % 10;
        int max = y_max;
        if (x_max > y_max) max = x_max;
        return y * 10 + max;
    }
}

int main () {
    int number; // natural
    cin >> number;
    cout << fatten(number) << endl;
}