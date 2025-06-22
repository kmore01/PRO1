//programa que, donats dos intervals, indica si un es troba dins de l’altre, i que calcula l’interval corresponent a la seva intersecció o indica si és buida

#include <iostream>
using namespace std;

int main () {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    if (d-a >= 0 and b-c >= 0) {
    if (a > c) {
        if (b <= d) cout << "1" << " , " << "[" << a << "," << b << "]" << endl;  
        else cout << "?" << " , " << "[" << a << "," << d << "]" << endl;
        }
    if (a < c) {
        if (b < d) cout << "?" << " , " << "[" << c << "," << b << "]" << endl;
        if (b >= d) cout << "2" << " , " << "[" << c << "," << d << "]" << endl;
        }
    if (a == c and b != d) {
        if (b < d) cout << "1" << " , " << "[" << c << "," << b << "]" << endl;
        else cout << "2" << " , " << "[" << c << "," << d << "]" << endl;
        }
    if ((a == c) and (b == d)) {
        cout << "=" << " , " << "[" << a << "," << d << "]" << endl;
        }
    }
    else {
        if (a > c and b <= d) cout << "1" << " , " << "[]" << endl;
        if (a > c and b > d) cout << "?" << " , " << "[]" << endl;
        if (a < c and b < d) cout << "?" << " , " << "[]" << endl;
        if (a < c and b >= d) cout << "2" << " , " << "[]" << endl;
        if (a == c and b != d and b < d) cout << "1" << " , " << "[]" << endl;
        if (a == c and b != d and b > d) cout << "2" << " , " << "[]" << endl;


    }
}




//d-a b-c