// programa que diu si una sequencia tanca correctament amb parentesis

#include <iostream>
using namespace std;

int main () {
    char para; // caracters
    int num = 0;
    while (num >= 0 and cin >> para) { // si el num es negatiu ja tanca malament
        if (para == '(') ++num;
        else --num;
    }
    if (num == 0) cout << "si" << endl;
    else cout << "no" << endl;
}