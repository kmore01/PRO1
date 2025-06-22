// program that encrypts messages with the “Caesar cipher”

#include <iostream>
using namespace std;

// function that returns the character corresponding to c when the constant is k
// Precondition: char
// Postcondition: char
char encoded(char c, int k) {
    if (c <= 'z' and c >= 'a') {
        return 'A' + (c - 'a' + k) % 26;
    }
    else if (c != '_') return c; // separator characters
    else return ' '; // _
}

int main () {
    int position; // natural > 0
    while (cin >> position) {
        char messague; //  lowercase letters and separator characters, no spaces
        cin >> messague;
        while (messague != '.') {
            cout << encoded(messague, position);
            cin >> messague;
        }
        cout << endl;
    }
}