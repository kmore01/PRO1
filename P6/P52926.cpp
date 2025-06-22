// program that reads a sequence of words until end and prints it in reverse
// order

#include <iostream>
using namespace std;

// function that reads words until "end" and prints it in reverse
void reverse_sentinel() {
    string sequence_words;
    cin >> sequence_words;
    if (sequence_words != "end") {
        reverse_sentinel(); // stopps until the last word and then cout (no ;)
        cout << sequence_words << endl;
    }
}

int main () {
    reverse_sentinel();
}