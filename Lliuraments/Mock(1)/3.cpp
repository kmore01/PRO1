// programa que diu les d's que estan seguides d'a sense cap b entre mig 
// i les c's que tenen abans una a pero cap b entre mig

#include <iostream>
using namespace std;

int main () {
    char lletra; // caracters sobre {a,b,c,d}
    bool b = false;
    bool a = false;
    int contador_c = 0, contador_d = 0;
    while (cin >> lletra) {
        if (lletra == b) b = true;
        if (lletra == a) a = true, b = false;
        else if (lletra == 'c' and a and not b) {
            ++contador_c;
            b = false;
            a = false;
        }
    }
    cout << contador_c << ' ' << contador_d << endl;
    



}