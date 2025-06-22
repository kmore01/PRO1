// program that reads a sequence and prints, for each word, all the other words
// of the sequence contained in it

#include <iostream>
#include <vector>
using namespace std;

// function that saves words in a vector
vector<string> read_in_vector() {
    int size;
    cin >> size;
    vector<string> V(size);
    for (int i = 0; i < size; ++i) {
        cin >> V[i];
    }
    return V;
}

// function that saves in a vector the parts contained in a word
vector<string> contan_parts(const string& v) {
    int size_v = v.size();
    vector<string> U();
    for (int i = 0; i < size_v; ++i) {
        U[i] = v[i];
    }
}

int main () {
    vector<string> V1 = read_in_vector();
}