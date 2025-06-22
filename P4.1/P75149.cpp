#include <iostream>
using namespace std;

int main () {
    char elem; // caracters
    cin >> elem;
    while (elem != 'a' and elem != '.') { // bucle mentre no trobi un .
        cin >> elem;
        }
    if (elem == 'a') {
        cout << "si" << endl;
    }
    else {
        cout << "no" << endl;
    }  
}