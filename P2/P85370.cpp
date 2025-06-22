// programa que dona la capital final

#include <iostream>
using namespace std;

int main () {
    cout.setf(ios::fixed);
    cout.precision(4);
    double co, i, t;
    char paraula;
    cin >> co >> i >> t >> paraula;
    if (paraula == 's') {
        cout << co * (1 + ((i / 100) * t)) << endl;
    }

    else {
        double k;
        k = 1 + (i / 100);
        int exp;
        exp = 1;
        while (exp < t) {
            k = k * (1 + (i / 100));
            exp = exp + 1;
        }
        cout << co * k << endl;
    }
}