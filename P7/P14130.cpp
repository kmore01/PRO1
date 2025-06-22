// program that calculates how many number are equal to the last of a sequence

#include <iostream>
#include <vector>
using namespace std;

int main () {
    int numseq; // natural > 0
    cin >> numseq;
    vector<int> x(numseq); // integer
    int count = 0;
    for (int i = 1; i <= numseq; ++i) { // loop that saves numbers, mejor poner i = 0
        cin >> x[i];
    }
    for (int i = 1; i < numseq; ++i) { // search equal numbers to the last one
        if (x[i] == x[numseq]) ++count;
    }
    cout << count << endl;
}