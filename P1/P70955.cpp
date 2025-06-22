//programa que passa una quantitat donada d’anys, dies, hores, minuts i segons a segons

#include <iostream>
using namespace std;

int main () {
    int a, d, h, m, s;
    cin >> a >> d >> h >> m >> s;
    int b, e, i, n;
    b= a*(365*24*60*60);
    e= d*(24*60*60);
    i= h*(60*60);
    n= m*(60);
    cout << b+e+i+n+s << endl;

}