/* Programa que diu si despres d'uns salts surt per l'esquerra, dreta o no surt
mai */

#include <iostream>
#include <vector>

using namespace std;

// Funcion que guarda elementos en un vector
vector<int> read_in_vector() {
    int size;
    cin >> size;
    vector<int> VNumbers(size);
    for (int i = 0; i < size; ++i) {
        cin >> VNumbers[i];
    }
    return VNumbers;
}

// Pre: 0 ≤ p < v.size()
string sortida(int p, vector<int>& v) {
    int size = v.size();
    vector<bool> aux(size, false);

    while(not aux[p]) {
        // En el momento que la p se repita, como sere true y saldra del bucle
        aux[p] = true;

        p += v[p];
        // Comprobamos si se ha salido del vector
        if (p >= size) {
            return "dreta";
        }
        else if (p < 0) {
            return "esquerra";
        }
    }

    return "mai";
}

int main () {
    vector<int> v1 = read_in_vector();
    int position;
    cin >> position;
    cout << sortida(position, v1) << endl;
}