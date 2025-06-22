// programa que escriu els nombres imparells i parells positius subseqüentment i després el seu doble

#include <iostream>
using namespace std;

int main () {
    int num;
    while (cin >> num) { 
        int i = 0;
        while (num > 0) { // giro el número
            i = i * 10 + num % 10;
            num = num / 10;
        }
        int cont = 1, senars = 0, parells = 0;
        while (i > 0) {
            if (i % 2 != 0) { // agafo els senars
                senars = senars * 10 + i % 10;
            }
            else if (i % 2 == 0 and i % 10 != 0) { // agafo els parells
                parells = parells * 10 + i % 10;
                cont *= 10;
            }
            i = i / 10;
        }
        cout << (senars * cont) + parells << ' ' << (senars * cont + parells) * 2 << endl;
    }
}