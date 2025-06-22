// programa que calcula el minim, el maxim i la mitjana de sequencies no buides

#include <iostream>
using namespace std;

int main () {
    int numseq; // natural
    cin >> numseq;
    for (int i = 0; i < numseq; ++i) { // vertical
        int num_elem; // natural > 0
        double num; 
        cin >> num_elem >> num;
        double max = num, min = num, sumatorio = num;
        for (int j = 1; j < num_elem; ++j) { // horitzontal
            cin >> num;
            if (num > max) max = num;
            if (num < min) min = num;
            sumatorio = sumatorio + num;
        }
        cout.setf(ios::fixed);
        cout.precision(4);
        cout << min << ' ' << max << ' ' << sumatorio / num_elem << endl;
    }
}