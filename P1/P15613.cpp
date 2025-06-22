//programa que diu si fa calor, si fa fred, o si s’està bé i si l'aigua bulluria o gelaria

#include <iostream>
using namespace std;

int main () {
    int x;
    cin >> x;
    if (x < 10) {
        cout << "fa fred" << endl;
        if (x <= 0) {
            cout << "l'aigua es gelaria" << endl;
        }
    }
    else if (x > 30) {
        cout << "fa calor" << endl;
        if (x >= 100) {
            cout << "l'aigua bulliria" << endl;
        }
    }
    else {
        cout << "s'esta be" << endl;
    }
}