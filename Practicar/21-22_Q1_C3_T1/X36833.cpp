// Programa que calcula el numero de puntos perdidos en una partida del UNO

#include <iostream>

using namespace std;

// Procedimiento que imprime los puntos perdidos en cada partida
void puntos_perdidos() {
    string primer_color = " ", segundo_color = " ";
    int count = 0;
    cin >> primer_color >> segundo_color;
    while (primer_color != "end" and segundo_color != "end") {
        if (primer_color != "mutlicolor" and segundo_color != "multicolor" and primer_color != segundo_color) {
            ++count;
        }
        // cout << primer_color << " " << segundo_color << endl;
        if (segundo_color != "multicolor") primer_color = segundo_color;
        cin >> segundo_color;
    }
    cout << count << endl; 
}

int main () {
    int partidas;
    cin >> partidas;
    for (int i = 0; i < partidas; ++i) {
        puntos_perdidos();
    }
}