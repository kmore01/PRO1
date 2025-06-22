// programa que diu si un numero es primer

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int numseq;
    cin >> numseq;
    int num;
    for (int i = 0; i < numseq; ++i) {
        cin >> num;
        if (num < 2) cout << num << " no es primer" << endl;
        else {
            bool primer = true;
            int j = 2;
            while (primer and j <= sqrt(num)) {
                if (num%j == 0) primer = false;
                ++j;
            }
            if (not primer) cout << num << " no es primer" << endl;
            else cout << num << " es primer" << endl;
        }
    }
}