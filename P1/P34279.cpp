//programa que afegeix un segon a una hora del dia, donades les seves hores, minuts i segons

#include <iostream>
using namespace std;

int main () {
    int h, m, s;
    cin >> h >> m >> s;
    int i;
    i= (h*(60*60)) + (m*(60)) + (s + 1);
    int a, b, c;
    a= (i%60);
    b= (i/60)%60;
    c= (i/60)/60;
    c%=24;
    cout << c/10 << c%10 << ":" << b/10 << b%10 << ":" << a/10 << a%10 << endl;

}