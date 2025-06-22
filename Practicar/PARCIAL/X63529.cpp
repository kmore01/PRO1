// programa que calcula l'hora d'arribada d'un tren incloent el retras

#include <iostream>
using namespace std;

int main () {
    int hora, minut, retard; // enters 0 ≤ h < 24 i 0 ≤ m < 60 i r ≥ 0
    cin >> hora >> minut >> retard;
    int temps;
    temps = (hora * 3600) + (minut * 60) + (retard * 60);
    int hora_resultat, minut_resultat;
    hora_resultat = temps / 3600;
    minut_resultat =  (temps / 60) - (temps / 3600 * 60);
    if (hora_resultat >= 24) hora_resultat %= 24;
    cout << hora_resultat / 10 << hora_resultat % 10 << ':' << minut_resultat / 10 << minut_resultat % 10 << endl;
}