//programa que llegeix tres nombres enterns i que n’escriu el màxim

#include <iostream>
using namespace std;

int main () {
    int a, b, c;
    cin >> a >> b >> c;

    int max;
    max = a;
    if (max >= b) {
        max = a;
    }
    else {
        max = b;
    }
    if (max >= c) {
        max = max;
    }
    else {
        max = c;
    }
    cout << max << endl;
}