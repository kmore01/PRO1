// program that prints the maximum of a sequence, the position and the
// poisition in the next sequence

#include <iostream>
using namespace std;

// reads a sequence ending in 0 and computes the parameters max and lpos
// Precondition: non negative integers ending in 0
// Postcondition: natural
void infoSequence(int& max, int& lpos) {
    int sequence;
    cin >> sequence;
    max = sequence;
    int lpos2 =  0;
    while (sequence != 0) {
        ++lpos2;
        if (sequence >= max) {
            max = sequence;
            lpos = lpos2;
        }
        cin >> sequence;
    }
}

int main () {
    int maximum, position;
    infoSequence(maximum, position);
    cout << maximum << ' ' << position << ' ';
    int sequence, position2 = 0;
    cin >> sequence;
    bool found = false;
    while (not found and sequence != 0) {
        ++position2;
        if (sequence == maximum) found = true;
        cin >> sequence;
    }

    if (found) cout << position2 << endl;
    else cout << '-' << endl;
}