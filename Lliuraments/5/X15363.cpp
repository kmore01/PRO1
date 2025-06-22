// program that reads a natural number n, and prints rombes
// No he sabido hacerlo sin utilizar bucles

#include <iostream>
using namespace std;

// function that prints sequences of rombes
// Precondition: natural
// Postcondition: no
void rombes(int size, int displace) {
    if (size == 1) { // base case
        for (int i = 0; i < displace - size; ++i) cout << ' '; // spaces
        cout << '*' << endl; // one asterisk
    }
    else { // general case
        rombes (size - 1, displace);
        for (int i = 0; i < size - 1; ++i) { // increasing part
            for(int j = 0; j < displace - i - 2; ++j) cout << ' '; // spaces
            for(int j = 0; j < 2 * i + 3; ++j) cout << '*'; // asterisks
            cout << endl;
        }
        for(int i = 0; i < size - 2; ++i) { // decreasing part
            for (int j = 0; j < displace + i + 1 - size; ++j) cout << ' ';
            for (int j = 0; j < 2 * size - 3 - 2 * i; ++j) cout << '*'; 
            cout << endl;
        }
        rombes(size - 1, displace); 
    }
}

int main() {
    int size; // natural
    while(cin >> size) {
        rombes(size, size);
        cout << endl;
    }
}