// programa que donat un enter major que dos i una serie de números calcula la variança d'aquests

#include <iostream>
using namespace std;

int main () {
    int numseq;
    cin >> numseq;
    double suma = 0, suma2 = 0;
    for (int i = 0; i < numseq; ++i) { // fem els càlculs necessaris
        double elem; 
        cin >> elem;
        suma = suma + elem;
        suma2 = suma2 + (elem * elem);
    }
    double resultat;
    resultat = ((1 / (double(numseq) - 1))) * suma2 - ((1 / double((numseq * (numseq - 1)))) * (suma * suma));
    cout.setf(ios::fixed);
    cout.precision(2); 
    cout << resultat << endl;
}