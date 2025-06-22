//programa que, donats dos intervals, indica si un es troba dins de l’altre
#include <iostream>
using namespace std;

int main () {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    if (a > c) {
        if (b <= d) cout << "1" << endl;  
        else cout << "?" << endl; 
    }
    if (a < c) {
        if (b < d) cout << "?" << endl;
        if (b >= d) cout << "2" << endl;
    }
    if (a == c and b != d) {
        if (b < d) cout << "1" << endl;
        else cout << "2" << endl;
    }
    if ((a == c) and (b == d)) cout << "=" << endl;

}