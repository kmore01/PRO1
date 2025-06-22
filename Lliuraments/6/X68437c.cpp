// program that prints the number of happy and sad sequences for each case

#include <iostream>
#include <vector>
using namespace std;

// function that calculates how many subsequences of three characters appears
// in a string (non-consecutive)
// precondition: c1,c2,c3 are pairwise different characters
// postcondition: returns the number of triples (i1,i2,i3) such that
// 0 <= i1 < i2 < i3 < s.size() and s[i1] = c1, s[i2] = c2, s[i3] = c3
int numberSubsequences(const string &s, char c1, char c2, char c3) {
    int s_size = s.size();
    int cont1 = 0, cont12 = 0, cont123 = 0;
    for (int i = 0; i < s_size; ++i) {
        if (c1 == s[i]) ++cont1; // '()' or ':'
        else if (c2 == s[i] and cont1 > 0) {
            for (int j = cont1; j > 0; --j) {
                ++cont12;
            }
        }
        else if (c3 == s[i] and cont12 > 0) {
            for (int j = cont12; j > 0; --j) {
                ++cont123;
            }
        }
    }
    return cont123;
}

// function that returns the count of the happy subsequences
// postcondition: returns the number of triples (i1,i2,i3) such that
// 0 <= i1 < i2 < i3 < s.size() and either s[i1]=':', s[i2]='-', s[i3]=')' or 
// s[i1]='(', s[i2]='-', s[i3]=':'.
int numberHappySubsequences(const string &s) {
    return numberSubsequences(s, ':', '-', ')') + numberSubsequences(s, '(', '-', ':');
}

// function that returns the count of the sad subsequences
// postcondition: returns the number of triples (i1,i2,i3) such that
// 0 <= i1 < i2 < i3 <s.size() and either s[i1]=':', s[i2]='-', s[i3]='(' or
// s[i1]=')', s[i2]='-', s[i3]=':'.
int numberSadSubsequences(const string &s);
int numberSadSubsequences(const string &s) {
    return numberSubsequences(s, ':', '-', '(') + numberSubsequences(s, ')', '-', ':');
}

int main () {
    string sequence; // characters ':' ':' '(' ')'
    while (cin >> sequence) {
        cout << numberHappySubsequences(sequence) << ' ';
        cout << numberSadSubsequences(sequence) << endl;
    }
}