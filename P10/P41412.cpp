/* Program that that sorts v in non-decreasing order using the insertion sort
algorithm */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function that saves numbers in a vector
vector<double> read_in_vector() {
    int size;
    cin >> size;
    vector<double> VNumbers(size);
    for (int i = 0; i < size; ++i) {
        cin >> VNumbers[i];
    }
    return VNumbers;
}

// Procedure that do the insertion sort of a vector
void insertion_sort(vector<double> &v) {
    int size = v.size();
    for (int i = 1; i < size; ++i) {
        // El elemento a ordenar junto a su posicion
        double x = v[i];
        int j = i;
        // Bucle hasta encontrar un elemento que sea mayor que el y salga del
        // bucle o parar si es el elemento mas pequeño
        while (j > 0 and v[j - 1] > x) {
            v[j] = v[j - 1];
            --j;
        }
        v[j] = x;
    }

    // Imprimir
    for (int i = 0; i < size; ++i) {
        cout << v[i] << ' ';
    }
    cout << endl;
}


int main () {
    vector<double> numbers = read_in_vector();
    insertion_sort(numbers);
}