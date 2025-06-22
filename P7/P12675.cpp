// program that returns the common elements between two vectors

#include <iostream>
#include <vector>
using namespace std;

// function that reads in a vector
vector<int> read_in_vector() {
    int size;
    cin >> size;
    vector<int> V(size);
    for (int i = 0; i < size; ++i) {
        cin >> V[i];
    }
    return V;
}
// function that returns the number of common elements in two vectors
// Precondition: the two vectors are in strictly increasing order
// Postcondition: integer
int common_elements(const vector<int>& X, const vector<int>& Y) {
    int size_X = X.size();
    int size_Y = Y.size();
    int count = 0, j = 0, i = 0;
    while (i < size_X and j < size_Y) { // busqueda
            if (X[i] == Y[j]) {
                ++count;
                ++i;
                ++j;
            }
            else if (X[i] > Y[j]) ++j;
            else ++i;
        }
    return count;
}

int main () {
    vector<int> X = read_in_vector();
    vector<int> Y = read_in_vector();
    cout << common_elements(X, Y) << endl;
}