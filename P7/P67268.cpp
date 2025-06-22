// program that prints the reversing order of a sequence

#include <iostream>
#include <vector>
using namespace std;

int main () {
    int numseq; // natural
    while (cin >> numseq) {
        if (numseq != 0) {
            vector<int> x(numseq); // integer
            for (int i = 0; i < numseq; ++i) cin >> x[i];
            cout << x [numseq - 1];
            for (int i = numseq - 2; i >= 0; --i) cout << ' ' << x[i];
            cout << endl;
        }
        else cout << endl;
    }
}
