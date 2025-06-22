// program that prints if a character is a letter or a digit, if it's a vowel
// or consonants and if it's an uppercase or lowercase letter

#include <iostream>
using namespace std;

// function that prints if the character c is an s or not, depending on the boolean b
void print_line(char c, string s, bool b) {
        cout << s << "('" << c << "') = ";
        if (b) cout << "true" << endl;
        else cout << "false" << endl;
}

int main () {
    char input; // printable character
    cin >> input;
    // letters
    if ((('A' <= input and input <= 'Z') or ('a' <= input and input <= 'z'))) { 
        print_line(input, "letter", true);
        bool vowels_1 = (input == 'a') or (input == 'e') or (input == 'i') or (input == 'o') or (input == 'u');
		bool vowels_2 = (input == 'A') or (input == 'E') or (input == 'I') or (input == 'O') or (input == 'U');
        // vowel or consonant
        if (vowels_1 or vowels_2) {
            print_line(input, "vowel", true);
            print_line(input, "consonant", false);
        }
        else {
            print_line(input, "vowel", false);
            print_line(input, "consonant", true);
        }
        // uppercase or lowercase
        if (input >= 'A' and input <= 'Z') {
            print_line(input, "uppercase", true);
            print_line(input, "lowercase", false);
        }
        else {
            print_line(input, "uppercase", false);
            print_line(input, "lowercase", true);
        }
        print_line(input, "digit", false);
    }
    // digits
    else if ('0' <= input and input <= '9') {
        print_line(input, "letter", false);
        print_line(input, "vowel", false);
        print_line(input, "consonant", false);
        print_line(input, "uppercase", false);
        print_line(input, "lowercase", false);
        print_line(input, "digit", true);
    }
    // other things
    else {
        print_line(input, "letter", false);
        print_line(input, "vowel", false);
        print_line(input, "consonant", false);
        print_line(input, "uppercase", false);
        print_line(input, "lowercase", false);
        print_line(input, "digit", false);
    }
}