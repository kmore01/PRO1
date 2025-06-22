// program that prints the rows, columns and the elements that are asked for

#include <iostream>
#include <vector>
using namespace std;

// function that saves elements in a matrix
vector< vector<int> > read_in_matrix() {
    int rows, columns;
    cin >> rows >> columns;
    vector< vector<int> > matrix(rows, vector<int>(columns));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            cin >> matrix[i][j];
        }
    }
    return matrix;
}

void row_column_elem(vector< vector<int> > matrix) {
    int rows = matrix.size();
    int columns = matrix[0].size();
    // operations
    string word;
    int number, r, c;
    while (cin >> word) {
        if (word == "column") { // print a column
            cin >> number;
            cout << "column " << number << ": ";
            int j = number - 1;
            cout << matrix[0][j];
            for (int i = 1; i < rows; ++i) {
                cout << ' ' << matrix[i][j];
            }
            cout << endl;
        }
        else if (word == "row") { // print a row
            cin >> number;
            cout << "row " << number << ": ";
            int i = number - 1;
            cout << matrix[i][0];
            for (int j = 1; j < columns; ++j) {
                cout << ' ' << matrix[i][j];
            }
            cout << endl;
        }
        else { // print an element
            cin >> r >> c;
            cout << "element " << r << ' ' << c << ": ";
            cout << matrix[r - 1][c - 1] << endl;
        }
    }
}

int main () {
    vector< vector<int> > matrix = read_in_matrix();
    row_column_elem(matrix);
}