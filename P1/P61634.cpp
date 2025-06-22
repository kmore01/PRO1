//programa que indica si un any és de traspàs o no

#include <iostream>
using namespace std;

int main () {
    int x;
    cin >> x;

    int a, b;
    a = ((x/10)/10)*100;
    b = x;

    if (((x%4) == 0 and a != b) or (a == b and (a/100)%4 == 0 )) cout << "YES" << endl;
    else cout << "NO" << endl;

}