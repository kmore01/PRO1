// program that reads a number n and a sequence of n or more words, and prints
// the n ‍last words in reverse order

#include <iostream>
using namespace std;

// function that 
void reverse_num(int num_words, int position) {
    ++position;
    string sequence_words;
    if (cin >> sequence_words and position >= num_words) {
        reverse_num(num_words, position); // stopps until the last word and then cout (no ;)
        cout << sequence_words << endl;
    }
    else if (cin >> sequence_words) reverse_num(num_words, position);
}

int main () {
    int num_words, position = 0;
    cin >> num_words;
    reverse_num(num_words, position);
}