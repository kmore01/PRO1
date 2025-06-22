// programa que donada la descripció d'un rectangle o cercle calcula l'àrea

#include <iostream>
#include <cmath>
using namespace std;

int main () {
    int numseq;
    cin >> numseq;
    for (int i = 0; i < numseq; ++i) {
        string elem; 
        cin >> elem;
        if (elem == "rectangle") {
            double b, h;
            cin >> b >> h;
            cout.setf(ios::fixed);
            cout.precision(6);
            cout << b * h << endl;
        }
        else {
            double r;
            cin >> r;
            cout.setf(ios::fixed);
            cout.precision(6);
            cout << M_PI * (r * r) << endl;
        }
    } 
}