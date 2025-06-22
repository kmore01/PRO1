// programa que calcula l’interval corresponent a la intersecció o indica si és buida entre dos intervals

#include <iostream>
using namespace std;

int main () {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    if (a > c and d-a >= 0) {
        if (b < d) cout << "[" << a << "," << b << "]" << endl;  
        else cout << "[" << a << "," << d << "]" << endl; 

    }
    else if (a <= c and b-c >= 0) {
        if (b <= d) cout << "[" << c << "," << b << "]" << endl;
        else cout << "[" << c << "," << d << "]" << endl;
    }
    else cout << "[]" << endl;




}

// Si b-c >= 0 o d-a >= 0, significa que es tallen.