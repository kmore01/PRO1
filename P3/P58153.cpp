// programa que llegeix dos nombres naturals n i m amb n ≥ m, i que per a cadascun escriu Hn − Hm

#include <iostream>
using namespace std;

int main () {
    int n, m;   // n i m naturals > 0 i n ≥ m
    while (cin >> n >> m) {
        double resultat = 0;
        // començem a i = n i per cada iteració restem 1 fins arribar a m
        for (int i = n; i > m; --i) {
            resultat = resultat + 1 / double(i);
        }
        cout.setf(ios::fixed);
        cout.precision(10);
        cout << resultat << endl;
    }
}