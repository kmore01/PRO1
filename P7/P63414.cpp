// program that reads a sequence of natural numbers and prints how many times it appears

#include <iostream>
#include <vector>
using namespace std;
const int SIZE_VEC = 1001;
const int INITIAL_VALUE= 1000000000;

vector<int> read_sequence() {
    vector<int> V(SIZE_VEC, 0);
    int num_elem;
    cin >> num_elem;
    for (int i = 0; i < num_elem; ++i) {
        int elem;
        cin >> elem;
        ++V[elem - INITIAL_VALUE]; // sum one to the repetion of the number
    }
    return V;
}

void print_vect (const vector<int>& X) {
    for (int i = 0; i < SIZE_VEC; ++i) {
        if (X[i] > 0) cout << i + INITIAL_VALUE << " : " << X[i] << endl;
    }
} 

int main () {
    vector<int> V1 = read_sequence();
    print_vect(V1);
}