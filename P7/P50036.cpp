// program that evaluates the polynomial at the point x
// we must use the Horner scheme

#include <iostream>
#include <vector>
using namespace std;

// function that saves elements in a vector
vector<int> read_in_vector() {
    int size;
    cin >> size;
    vector<int> V(size);
    for (int i = 0; i < size; ++i) {
        cin >> V[i];
    }
    return V;
}

// function that calculates the horner scheme
int evaluate(const vector<int>& p, int x) { 
    int size_p = p.size();
    int result = p[size_p - 1]; 
    for (int i = size_p - 2; i >= 0; --i) {
        result = result * x + p[i];
    }
    return result;
}

int main () {
    vector<int> V1 = read_in_vector();
    int value_x;
    cin >> value_x;
    cout << evaluate(V1, value_x) << endl;
}