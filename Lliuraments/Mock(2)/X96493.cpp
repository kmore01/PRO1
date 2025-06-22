// Programa que calcula en que posicion se encuentra el primer elemento de una
// pareja de numeros consecutivos

#include <iostream>
#include <vector>

using namespace std;

// Funcion que guarda enteros en un vector
vector<int> read_in_vector() {
    int size;
    cin >> size;
    vector<int> VNumeros(size);
    for (int i = 0; i < size; ++i) {
        cin >> VNumeros[i];
    }
    return VNumeros;
}

// Pre: Sea n el tamaño, v.size(). Entonces, para cada i en {0..n-2}, se cumple que |v[i] - v[i + 1]| <= 2.
// Además, hay exactamente una i en {0..n-2} que cumple |v[i] - v[i + 1]| = 1.
// Post: La función devuelve ese i en {0..n-2} que cumple |v[i] - v[i + 1]| = 1.
int positionDistance1(const vector<int> &v) {
    int left = 0, right = v.size() - 1;
    while (left < right) {
        int mid = (left + right) / 2;
        // Comparamos la paridad el elemento medio
        // Cuando la paridad cambie, esa sera la posicon buscada

        // Hacia la derecha
        if (v[mid] % 2 == v[left] % 2 and v[mid] % 2 == v[mid + 1] % 2) {
            left = mid + 1;
        }
        // Hacia la izquierda
        else if (v[mid] % 2 == v[right] % 2 and v[mid] % 2 == v[mid + 1] % 2){
            right = mid - 1;
        }
        // Si es justo el elemento buscado
        else {
            left = mid;
            right = left;
        }
    }

    return left;
}

int main () {
    vector<int> V = read_in_vector();
    cout << positionDistance1(V) << endl;
}