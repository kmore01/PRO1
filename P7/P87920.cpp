// program that calculates from a sequence if there is any number equal to the
// sum of the rest 

#include <iostream>
#include <vector>
using namespace std;

// function that saves elements in a vector
vector<int> read_in_vector(int size) {
    vector<int> V(size);
    for (int i = 0; i < size; ++i) {
        cin >> V[i];
    }
    return V;
}

bool number_equal_sum_rest(const vector<int>& X) { // x vector sabemos
    bool found = false;
    int size_X = X.size(), all = 0;
    for (int i = 0; i < size_X; ++i) all += X[i];
    int j = 0;
    while (not found and j < size_X) {
        if (X[j] == all - X[j]) found = true;
        ++j;
    }
    return found;
}

int main () {
    int size;
    while (cin >> size) {
        vector<int> V1 = read_in_vector(size); // base vector
        if (number_equal_sum_rest(V1)) cout << "YES" << endl;
        else cout << "NO" << endl;

    }
}