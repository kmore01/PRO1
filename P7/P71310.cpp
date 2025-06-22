// program that calculates the scalar products of two vectors

#include <iostream>
#include <vector>
using namespace std;

// function that saves elements in a vector
vector<double> read_in_vector() {
    int size;
    cin >> size;
    vector<double> V(size);
    for (int i = 0; i < size; ++i) {
        cin >> V[i];
    }
    return V;
}

// function that calculates the scalar_product of two vectors
double scalar_product(const vector<double>& u, const vector<double>& v) {
    int size_u = u.size(); // it doesn't matter because the sizes are the same
    double result = 0;
    for (int i = 0; i < size_u; ++i) {
        result += u[i] * v[i];
    }
    return result;
}

int main () {
    vector<double> V1 = read_in_vector();
    vector<double> V2 = read_in_vector();
    cout << scalar_product(V1, V2) << endl;
}