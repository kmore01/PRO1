// program that prints a list of words in reverse order and reverse letters

#include <iostream>
#include <vector>
using namespace std;

// function that saves elements in a vector
vector<string> read_in_vector() {
    int size; // natural
    cin >> size;
    vector<string> V(size);
    for (int i = 0; i < size; ++i) {
        cin >> V[i];
    }
    return V;
}

// function that prints the revers word in reverse order
void reverse_order(vector<string>& X) {
    int size_X = X.size();
    for (int i = size_X - 1; i >= 0; --i) {
        // here we emulate that the word is another vector and we start printing since the last position
        for (int j = X[i].size() - 1; j >= 0; --j) { 
            cout << X[i][j]; 
        } 
        cout << endl;
    }
}

int main () {
    vector<string> V1 = read_in_vector();
    reverse_order(V1);
}
