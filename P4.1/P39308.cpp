// programa que escriu en ordre tots els divisors d'un numero
// tot divisor mes petit que l’arrel de n te un divisor corresponent mes gran 
// que l’arrel de n

#include <iostream>
#include <cmath>
using namespace std;

int main () {
    int num; // 1 < natural < 10^9
    while (cin >> num) {
        cout << "divisors de " << num << ":";
        for (int i = 1; i < sqrt(num); ++i) { // primer bucle divisors petits
            if (num % i == 0) cout << ' ' << i;
        }
        for (int j = sqrt(num); j > 0; --j) { // segon bucle divisors grans
            if (num % j == 0) cout << ' ' << num / j;
        }
        cout << endl;
    }
}