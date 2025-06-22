//programa que llegeix un real escriu la part entera inferior, la part entera superior l’arrodoniment de x

#include <iostream>
using namespace std;

int main () {
    double x;
    cin >> x;
    cout << int(x) << ' ' << int(x)+int(x-int(x)-1)+1 << ' ' << int(2*x - int(x)) << endl;
    
}