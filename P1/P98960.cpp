//programa que llegeix una lletra i l’escriu en minúscula si era majúscula, o en majúscula si era minúscula

#include <iostream>
using namespace std;

int main () {
    char a;
    cin >> a;
    char p, g;
    p= a - 'b' + 'B';
    g= a - 'B' + 'b';
    if (a >= 97) cout << p << endl;
    else cout << g << endl;



}