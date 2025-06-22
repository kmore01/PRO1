// programa que compta quantes setmanes acabes en positiu tenint en compte despeses, diners inicials, setmanes i assignacions setmanals

#include <iostream>
using namespace std;

int main () {
    int despeses, euros, setmanes;
    cin >> despeses >> euros >> setmanes;
    int positiu = 0;
    for (int i = 0; i < setmanes; ++i) { // bucle per agafar les assignacions
        int elem;
        cin >> elem; 
        if ((euros + elem - despeses) > 0) { // agafar les setmanes positives
            ++positiu;
        }
        euros = euros + elem - despeses;
    }
    cout << positiu << endl;
}