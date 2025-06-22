// program that transposes a square matrix

#include <iostream>
#include <vector>
using namespace std;
typedef vector< vector<int> > MatrizChar;

// function that saves elements in a matrix
vector< vector<int> > read_in_matrix(int size) {
    vector< vector<int> > matrix(size, vector<int>(size));
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            cin >> matrix[i][j];
        }
    }
    return matrix;
}

// function that transposes a square matrix
// precondition: m is a square matrix n × n with n ≥ 0
void transpose(MatrizChar& m) {
    int size_ = m.size();
    MatrizChar trans(size_, vector<int>(size_));
    for (int i = 0; i < size_; ++i) {
        for (int j = 0; j < size_; ++j) {
            trans[i][j] = m[j][i];
        }
    }
    m = trans;
}

int main () {
    int size;
    cin >> size;
    vector< vector<int> > matrix = read_in_matrix(size);
    transpose(matrix);
    for (int i = 0; i < size; ++i) {
        cout << matrix[i][0];
        for (int j = 1; j < size; ++j) {
            cout << ' ' << matrix[i][j];
        }
        cout << endl;
    }
}