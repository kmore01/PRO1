// Programa que calcula el numero de caras felices o tristes

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Pre: s is formed with three different characters c1,c2,c3, and is of the form c1...c1c2...c2c3...c3.
// Post: n1, n2, n3 are the number of occurrences of c1, c2, c3 in s, respectively.
// Procedimiento que busca cuantas veces aparece cada caracter utilizando la
// busqueda binaria
void numberOccurrences(const string &s, int &n1, int &n2, int &n3) {
    // Utiliziaremos la busqueda binaria, asi que declaramos la izquierda y
    // derecha
    int left = 0;
    int right = s.length() - 1;

    // Busqueda ultimo caracter
    while (left < right) {
        int mid = (left + right) / 2;
        // Lo hemos encontrado
        if (s[mid] == s[s.length() - 1]) right = mid;
        // Esta en la parte alta
        else left = mid + 1;
        // Como es el ultimo caracter, no puede estar en la parte baja
    }

    // Volvemos a restaurar los valores de left y right
    int last_char_left = left;
    left = 0;
    right = s.length() - 1;

    // Busqueda primer elemento
    while (left < right) {
        int mid = (left + right) / 2;
        // Lo hemos encontrado
        if (s[mid] == s[0]) left = mid  + 1;
        // Esta en la parte baja
        else right = mid;
        // Como es el primer caracter, no puede estar en la parte alta
    }

    n1 = left;
    n3 = s.length() - last_char_left;
    // Busqueda elemento intermedio (no hace falta bucle, son todos los
    // elementos que faltan)
    n2 = s.length() - n1 - n3;
}

// Pre: s begins with one or more occurrences of a character c1, followed by one or more
// occurrences of a character c2, followed by one or more occurrences of a character c3,
// and there are no more characters in s.
// moreover, either c1c2c3 = ":-)" or c1c2c3 = "(-:" or c1c2c3 = ":-(" or c1c2c3 = ")-:".
// Post: If c1c2c3 = ":-)" or c1c2c3 = "(-:", the function returns the number of happy subsequences.
// If c1c2c3 = ":-(" or c1c2c3 = ")-:", the function returns the number of sad subsequences.
// Funcion que devuelve el nombre de subsequencias felices o tristes
int numberHappyOrSadSubsequences(const string &s) {
    int num_c1, num_c2, num_c3;
    num_c1 = num_c2 = num_c3 = 0;
    // Ponemos en las variables las veces que aparece cada una de ellas
    numberOccurrences(s, num_c1, num_c2, num_c3);
    // Las multiplicamos para contar todas las combianciones posibles
    return (num_c1 * num_c2 * num_c3);
}

int main () {
    string sequence; // caracteres ':' '-' '(' ')'
    while (cin >> sequence) {
        cout << numberHappyOrSadSubsequences(sequence) << endl;
    }
}