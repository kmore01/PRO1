// program that prints if it has two elements such that their sum is a prime
// number

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

// function that calculates the sum of the different integers
vector<int> sum_of_elem(const vector<int>& Y) {
    int size_Y = Y.size();
    vector<int> U(((size_Y) * (size_Y - 1)) / 2); 
    int cont = 0;
    for (int i = 0; i < size_Y; ++i) {
        for(int j = 1; j < size_Y; ++j) {
            if (cont < U.size()) {
                U[cont] = Y[i] + Y[j + i];
            }
        }
    }
    return U;
}

bool is_prime(int x, int divisor = 2) {
    bool primer = false;
    if (x < 2) primer = false; // base case
    else if (divisor * divisor > x) primer = true; // base case
    else if (x % divisor == 0) primer = false; // base case
    else { // general case
        primer = is_prime(x, divisor + 1);
    }
    return primer;
}

int main () {
    int size;
    while (cin >> size) {
        vector<int> V1 = read_in_vector(size);
        vector<int> V2 = sum_of_elem(V1);
        int size_V2 = V2.size(), i = 0;
        bool found = false; 
        while (not found and i < size_V2) {
            if (is_prime(V2[i], 2)) found = true;
            ++i;
        }
        if (found) cout << "yes" << endl;
        else cout << "no" << endl;
    }
}