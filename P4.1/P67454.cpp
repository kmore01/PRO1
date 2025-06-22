// programa que calcula quantes as hi ha abans del primer punt

#include <iostream>
using namespace std;

int main () {
    char lletra; // caracter
    cin >> lletra;
    int contador = 0;
    while (lletra != '.') {
        if (lletra == 'a') ++contador;
        cin >> lletra;
    }
    cout << contador << endl;
}