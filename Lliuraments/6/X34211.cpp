// program that reads a sequence of numbers and prints the result of summing or
// substracting each position of the vector according if the character is + or -

#include <iostream>
#include <vector>
using namespace std;

// function that saves integer numbers in a vector
vector<int> read_in_vector() {
    int size; // size > 0
    cin >> size;
    vector<int> V(size);
    for (int i = 0; i < size; ++i) {
        cin >> V[i];
    }
    return V;
}

int main () {
    vector<int> V1 = read_in_vector();
    int V1_size = V1.size();
    string operacion; // characters '+' and '-'
    while (cin >> operacion) {
        int sum = 0;
        for (int i = 0; i < V1_size; ++i) {
            if (operacion[i] == '+') sum = sum + V1[i]; 
            else sum = sum - V1[i];
        }
        cout << sum << endl;
    }
}