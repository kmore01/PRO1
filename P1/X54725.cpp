//programa que llegeix dos nombres i escriu el mÃ©s petit

#include <iostream>
using namespace std;

int main () {
    int a, b;
    cin >> a >> b;
    if (a >= b) {
        cout << b << endl;
    }
    else {
        cout << a << endl;;
    }
}