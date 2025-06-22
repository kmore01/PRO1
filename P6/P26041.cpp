// program that reads a sequence of words and prints it in reverse order
// tail recursion

#include <iostream>
using namespace std;

// function that reads words and prints it in reversed
void reverse() {
    string sequence_words;
    if (cin >> sequence_words) {
        reverse(); // stopps until the last word and then cout (no ;)
        cout << sequence_words << endl;
    }
}

int main () {
    reverse();
}