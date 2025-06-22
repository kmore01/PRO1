/* Programa que imprimeix la diferencia entre dos vectors */

#include <iostream>
#include <vector>

using namespace std;

// Funcion que guarda elementos en un vector
vector<double> read_in_vector() {
    int size;
    cin >> size;
    vector<double> VNumbers(size);
    for (int i = 0; i < size; ++i) {
        cin >> VNumbers[i];
    }
    return VNumbers;
}

// Funcion que devuelve una tabla ordenada con la diferencia entre v1 y v2
vector<double> diferencia(const vector<double> &v1, const vector<double> &v2) {
    int size_v1 = v1.size(), size_v2 = v2.size();
    vector<double> dif;

    // Idea: Usaremos bianry search
    for (int i = 0; i < size_v1; ++i) {
        int left = 0, right = size_v2 - 1;
        bool found = false;

        while (not found and left <= right) {
            int mid = (left + right) / 2;

            // Si el elemento es igual, no lo ponemos
            if (v2[mid] == v1[i]) {
                found = true;
            }
            // El elemento es mas grande que la mitad
            else if (v2[mid] < v1[i]) {
                left = mid + 1;
            }
            // El elementro es mas pequeño que la mitad
            else {
                right = mid - 1;
            }
        }

        // Asegurarse de que el vector dif no esté vacío y que v1[i] no sea igual al último elemento
        if (not found) {
            if (dif.size() == 0) {
                dif.push_back(v1[i]);
            }
            else if (v1[i] != dif[dif.size()- 1]) {
                dif.push_back(v1[i]);
            }
        }
    }

    return dif;
}

void print_vector(const vector<double> &ans) {
    int size = ans.size();
    for (int i = 0; i < size; ++i) {
        cout << ans[i] << ' ';
    }
    cout << endl;
}

int main () {
    vector<double> v1 = read_in_vector();
    vector<double> v2 = read_in_vector();
    vector<double> v3 = diferencia(v1, v2);
    print_vector(v3);
}