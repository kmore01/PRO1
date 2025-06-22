/* Programa que diu quan es troba un riu amb els rius 1, 3 o 9 */

#include <iostream>
#include <vector>

using namespace std;

// Funcion que suma los digitos de un numero mas ese numero
int suma_digits(int number) {
	int n = number;
	while (number > 0) {
		n += number % 10;
		number /= 10;
	}
	return n;
}

// Pre: Es té 1 ≤ n ≤ 16384
// Funcion que devuelve el primer valor para el cual el rio n encuentra los
// rios 1, 3 o 9
int trobada_de_rius(int n) {
    int riu1 = 1, riu3 = 3, riu9 = 9;
    while (n != riu1 and n != riu3 and n!= riu9) {
        while (riu1 < n) riu1 = suma_digits(riu1);
        while (riu3 < n) riu3 = suma_digits(riu3);
        while (riu9 < n) riu9 = suma_digits(riu9);
        if (n != riu1 and n != riu3 and n != riu9) n = suma_digits(n);
    }
    return n;
}

int main () {
    int riu;
    while (cin >> riu) {
        cout << trobada_de_rius(riu) << endl;
    }
}