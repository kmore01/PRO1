// program that prints if a string is palindrome
// A words is palindrome if it reads the same from left to right than from
// right to left

#include <iostream>
#include <vector>
using namespace std;

// function that returns if a word is palindrome
bool is_palindrome(const string& s) {
    int size_s = s.size();
    int i = 0, j = size_s;
    bool palindrome = true;
    while (palindrome and i < size_s) {
        if (s[i] != s[j - 1]) palindrome = false;
        ++i;
        --j;
    }
    return palindrome;
}

int main () {
    string input;
    cin >> input;
    if (is_palindrome(input)) cout << "yes" << endl;
    else cout << "no" << endl;
}