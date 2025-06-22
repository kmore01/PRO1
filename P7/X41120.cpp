// program that prints how many picks are, their altitude in order and which of
// them are higher than the last pick

#include <iostream>
#include <vector>
using namespace std;

// function that saves altitudes in a vector
vector<int> read_in_vector() {
    int size;
    cin >> size;
    vector<int> V(size);
    for (int i = 0; i < size; ++i) {
        cin >> V[i];
    }
    return V;
}

// precondition: |v|≥ 3
// postcondition : returns a vector containing the height of all the peaks in v (in the same order)
vector<int> obtain_peaks(const vector<int>& v) {
    int size_v = v.size();
    vector<int> peaks(0); // size??
    for (int i = 1; i < size_v - 1; ++i) { // -1 cambio
        if ((v[i] > v[i - 1]) and (v[i] > v[i + 1])) peaks.push_back(v[i]); // ?
    }
    return peaks;
}

int main () {
    vector<int> V1 = read_in_vector();
    vector<int> V2 = obtain_peaks(V1);
    int size_V2 = V2.size();
    int last = 0;
    if (size_V2 != 0) last = V2[size_V2 - 1];
    cout << size_V2 << ":";
    bool found = false;
    for (int i = 0; i < size_V2; ++i) { // HACE FALTA EMPEZAR EN 0?
        cout << ' ' << V2[i];
        if (V2[i] > last) found = true;
    }
    cout << endl;
    if (found) {
        int contador = 0;
        for (int i = 0; i < size_V2; ++i) {
            if (V2[i] > last) {
                if (contador == 0) cout << V2[i];
                else cout << ' ' << V2[i];
                contador = 1;
            }
        }
        cout << endl;
    }
    else cout << '-' << endl;
}