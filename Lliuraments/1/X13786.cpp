//programa que li diu a una persona que sembla més jove depenent la seva edat

#include <iostream>
using namespace std;

int main () {
    string nada;
    string NOM;
    int EDAT;
    while (cin >> nada >> nada >> nada >> NOM >> nada >> nada >> nada >> EDAT >> nada >> nada) {
        cout << NOM << ", you look younger. I thought you were " << EDAT - (EDAT / 10) << " years old." << endl;
    }
}