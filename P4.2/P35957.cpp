// programa que diu qui guanya en un joc entre l'Anna i el Bernat

#include <iostream>
using namespace std;

int main () {
    int numero_nombres;
    cin >> numero_nombres;
    int i = 0;
    bool Anna = false, Bernat = false;
    while ((not Anna and not Bernat) and i < 2 * numero_nombres) {
        int numero;
        cin >> numero;
        int num_anna = numero, num_bernat = numero;
        if (numero % 2 == 0) {
            if (i % 2 == 0) Bernat = true;
            else Anna = true;
        }
        else if (i == numero_nombres / 2) {
            if (i % 2 == 0 and num_anna != numero) Bernat = true;
            else if (i % 2 != 0 and num_bernat != numero) Anna = true;
        }
        // l'Anna insereix posicions pars, Bernat posicions senars

        if (i % 2 == 0) num_anna = numero;
        else num_bernat = numero;
        ++i;
    }

    if (Anna) cout << 'A' << endl;
    else if (Bernat) cout << 'B' << endl;
    else cout << '=' << endl;


}