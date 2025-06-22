// programa que compta el nombre d'as

#include <iostream>
using namespace std;

int main () {
    char frase;
    cin >> frase;
    int as;
    as = 0;
    while (frase != '.') {
        if (frase == 'a') {
            as = as + 1;
        }
        cin >> frase; // per mirar el següent caràcter de la frase
    }
    cout << as << endl;
}