// program that returns the concatenation of v1 and v2

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

// function that link the two vectors
vector<int> concatenation(const vector<int>& V1, const vector<int>& V2) {
    vector<int> V3(V1.size() + V2.size());
    int size_V3 = V3.size();
    int size_V1 = V1.size();
    for (int i = 0; i < size_V1; ++i) {
        V3[i] = V1[i];
    }
    int j = 0;
    for (int i = size_V1; i < size_V3; ++i) {
        V3[i] = V2[j];
        ++j;
    }
    return V3;
}

int main () {
    vector<int> V1 = read_in_vector();
    vector<int> V2 = read_in_vector();
    vector<int> V3 = concatenation(V1, V2);
    for (int i = 0; i < V3.size(); ++i) {
        cout << V3[i] << ' ';
    }
    cout << endl;
}