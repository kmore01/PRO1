// programa que diu les hores que han passat desde l'inici de la renda fins que
// aquesta finalitza

#include <iostream>
using namespace std;

int main () {
    int inici_hora, inici_minut, final_hora, final_minut;
    cin >> inici_hora >> inici_minut >> final_hora >> final_minut;
    int resultat_hores, resultat_minuts;
    resultat_hores = final_hora - inici_hora;
    resultat_minuts =  final_minut - inici_minut;
    if (resultat_minuts < 0) {
        resultat_minuts += 60;
        --resultat_hores;
    }
    if (resultat_hores < 0) resultat_hores += 24;
    cout << resultat_hores / 10 << resultat_hores % 10 << ':' << resultat_minuts / 10 << (resultat_minuts) % 10 << endl;
}