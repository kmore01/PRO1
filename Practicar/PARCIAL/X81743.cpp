// programa que diu les lletres que estan entre dues lletres en orde alfabetic

#include <iostream>
using namespace std;

int main () {
    int num_lletres; // enter > 0
    char lletra1, lletra2, sequencia; // lletres minuscules
    cin >> num_lletres >> lletra1 >> lletra2;
    int contador = 0;
    for (int i = 0; i < num_lletres; ++i) {
        cin >> sequencia;
        if (lletra1 <= sequencia and sequencia <= lletra2) ++contador;
    }
    cout << contador << endl;
}