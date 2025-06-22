// Programa que ordena a los jugadores segun los doble triples-dobles y
// triples-dobles que han conseguido

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Jugador {
    string nombre;
    int dtd;        // doble triple-doble
    int td;         // triple-doble (que no son doble triple-doble)
};

// Pre: p >= 0; en la entrada hay un nombre seguido de sus estadísticas en p partidos
// Post: jug está inicializado convenientemente con los datos de la entrada
// Procedimiento que lee los juadores y almacena su informacion
void leer_jugador(int p, Jugador& jug) {
    cin >> jug.nombre;
    // Calculamos los doble triple-dobles y triple-dobles
    for (int i = 0; i < p; ++i) {
        int stats, puntos = 0, puntos2 = 0;
        cin >> stats;
        if (stats >= 20) ++puntos;
        else if (stats >= 10) ++puntos2;
        cin >> stats;
        if (stats >= 20) ++puntos;
        else if (stats >= 10) ++puntos2;
        cin >> stats;
        if (stats >= 20) ++puntos;
        else if (stats >= 10) ++puntos2;
        cin >> stats;
        if (stats >= 20) ++puntos;
        else if (stats >= 10) ++puntos2;
        cin >> stats;
        if (stats >= 20) ++puntos;
        else if (stats >= 10) ++puntos2;

        if (puntos >= 3) ++jug.dtd;
        else if (puntos2 + puntos >= 3) ++jug.td;
    }
}

// Funcion que ordena dos jugadores segun el nombre de dobles triple-dobles,
// triples-doble y orden lexicografico del nombre
bool order(Jugador a, Jugador b) {
    if (a.dtd != b.dtd) return a.dtd > b.dtd;
    else if (a.td != b.td) return a.td > b.td;
    else return a.nombre < b.nombre;
}

// Procedimiento que imprime el vector de jugadores ordenado
void imprimir_respuesta(vector<Jugador> &inf) {
    sort(inf.begin(), inf.end(), order);
    for (int i = 0; i < inf.size(); ++i) {
        cout << inf[i].nombre << ' ' << inf[i].dtd << ' ' << inf[i].td << endl;
    }
}

int main () {
    int partidos; // entero ≥ 0
    cin >> partidos;
    int numero_jugadores; // entero ≥ 0
    cin >> numero_jugadores;
    vector<Jugador> info(numero_jugadores);
    for (int i = 0; i < numero_jugadores; ++i) {
        leer_jugador(partidos, info[i]);
    }
    imprimir_respuesta(info);
}