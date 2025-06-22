// Programa que busca la posicion del elemento a partir del cual se cambia de
// paridad

#include <iostream>
#include <vector>
using namespace std;

vector<int> leer_vector(int size) {
    vector<int> input(size);
    for (int i = 0; i < size; ++i) {
        cin >> input[i];
    }

    return input;
}

// Pre: Sea n el tamaño, v.size(). Entonces, para cada i en {0..n-2}, se cumple que |v[i]-v[i+1]|<=2.
// Además, hay exactamente una i en {0..n-2} que cumple |v[i]-v[i+1]|=1.
// Post: La función devuelve ese i en {0..n-2} que cumple |v[i]-v[i+1]|=1.
int positionDistance1(const vector<int> &v) {
    int left = 0, right = v.size() - 1;

    while (left < right) {
        int mid = (left + right) / 2;

        if (v[left] % 2 == v[mid] % 2 and v[mid] % 2 == v[mid + 1] % 2) left = mid + 1;

        else if (v[right] % 2 == v[mid] % 2 and v[mid] % 2 == v[mid + 1] % 2) right = mid - 1;

        else {
            left = mid;
            right = left;
        }
    }

    return left;
}

int main () {
    int size;
    while (cin >> size) {
        vector<int> VNum = leer_vector(size);
        cout << positionDistance1(VNum) << endl;
    }
}