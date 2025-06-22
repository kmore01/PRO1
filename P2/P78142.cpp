// programa que llegeix una seqüència de nombres i que escriu la mitjana

#include <iostream>
using namespace std;

int main () {
    int i = 0;
    double num, suma = 0;
    while (cin >> num) { // faig un bucle on suma tots aquells positius i comptarà quants valors hem introduït
        if (num > 0) {
            suma = suma + num;
        }
        ++i;
    }
    cout.setf(ios::fixed);
    cout.precision(2);
    cout << suma / double(i) << endl;
}