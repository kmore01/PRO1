//programa que indica si una lletra és majúscula o minúscula i si és vocal o consonant

#include <iostream>
using namespace std;

int main () {
    char lletra;
    cin >> lletra;
    if (lletra <= 'Z' and lletra >= 'A') {
        cout << "majuscula" << endl;
        if (lletra == 'A' or lletra == 'E' or lletra == 'I' or lletra == 'O' or lletra == 'U')
            cout << "vocal" << endl;
        else cout << "consonant" << endl;
    }
    else {
        cout << "minuscula" << endl;
        if (lletra == 'a' or lletra == 'e' or lletra == 'i' or lletra == 'o' or lletra == 'u')
            cout << "vocal" << endl;
        else cout << "consonant" << endl;
    }
}