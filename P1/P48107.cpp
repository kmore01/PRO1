//programa que llegeix dos nombres i escriu la divisiÃ³ entera d i el residu r

#include <iostream>
using namespace std;

int main () {
    int a, b;
    cin >> a >> b;
    int d, r;
    d = a / b;
    r = a % b;
    cout << d << ' ' << r << endl;
}