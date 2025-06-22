//programa que, donada una quantitat de segons, diu quantes hores, minuts i segons representa aquell nombre

#include <iostream>
using namespace std;

int main () {
    int n;
    cin >> n;
    double s, m, h;
    s= n%60;
    m= (n/60)%60;
    h= (n/60)/60;
    cout << h << " " << m << " " << s << endl; 

}