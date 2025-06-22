/* Program that leaves a vector totally in non-decreasing order */

#include <iostream>
#include <vector>

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

// Pre: We have |v| ≥ 1. Moreover, the positions 0 to |v| − 2 of v are in
// non-decreasing order
// Procedure that inserts the last element of a vector in non-decreasing order
void insert(vector<double> &v) {
    int size = v.size();
    double last_element = v[size - 1];
    vector<double> answer(size);

    // El primer elemento no hace falta mirarlo?
    int i = 0;
    bool found = false;
    double last;
    while (not found and i < size) {
        if (last_element < v[i]) {
            last = v[i];
            answer[i] = last_element;
            found = true;
        }
        else answer[i] = v[i];
        ++i;
    }

    while (i < size) {
        answer[i] = last;
        last = v[i];
        ++i;
    }
    v = answer;
}

// Idea: como los elementos del vector ya estan ordenados en orden creciente
// (menos el ultimo), no hace falta mirar todos los numeros

int main () {
    vector<double> numbers = read_in_vector();
    insert (numbers);
}