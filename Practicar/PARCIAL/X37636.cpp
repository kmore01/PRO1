// programa que transforma el graus Celsius a Fahrenheit i viceversa

#include <iostream>
using namespace std;

int main () {
    cout.setf(ios::fixed);
    cout.precision(1);
    const double conv1 = 1.8, conv2 = 32;
    int numseq; // enter no negatiu
    cin >> numseq;
    for (int i = 0; i < numseq; ++i) {
        char tipus; // letra F (Fahrenheit) o C (Celsius)
        double graus; // sequencia de mesures de temperatura
        cin >> tipus >> graus;
        if (tipus == 'F') cout << 'C' << ' ' << (graus - conv2) / conv1 << endl;
        else cout << 'F' << ' ' << (conv1 * graus) + conv2 << endl;
    
    }
}