/* Programa que calcula el baricentro y determina si cumple diferentes
propiedades */

#include <iostream>
#include <vector>

using namespace std;

struct Punto {
    double x,y;
};

// function that saves words in a vector
vector<Punto> read_in_vector(int size) {
    vector<Punto> VPuntos(size);
    for (int i = 0; i < size; ++i) {
        cin >> VPuntos[i].x >> VPuntos[i].y;
    }
    return VPuntos;
}

// Funcion que calcula el baricentro y lo imprime
void calcular_imprimir_baricentro (const vector<Punto> &v) {
    cout.setf(ios::fixed);
    cout.precision(2);

    cout << "baricentro: ";
    int size = v.size(), sum_x = 0, sum_y = 0;
    for (int i = 0; i < size; ++i) {
        sum_x += v[i].x;
        sum_y += v[i].y;
    }
    cout << '(' << sum_x / double(size);
    cout << ',' << sum_y / double(size) << ')' << endl;
}

// Funcion que calcula el baricentro y lo imprime
Punto baricentro2 (const vector<Punto> &v) {
    Punto baricentro;
    int size = v.size(), sum_x = 0, sum_y = 0;
    for (int i = 0; i < size; ++i) {
        sum_x += v[i].x;
        sum_y += v[i].y;
    }
    baricentro.x = sum_x / double(size);
    baricentro.y = sum_y / double(size);

    return baricentro;
}

// El vector contiene al menos dos elementos diferentes
bool prop1 (const vector<Punto> &v) {
    int size = v.size();
    bool different = false;
    int i = 1;
    while (not different and i < size - 1) {
        if (v[i].x != v[i + 1].x or v[i].y != v[i + 1].y) different = true;
        ++i;
    }

    return different;
}

// La suma de todas las coordenadas x’s de los puntos del vector coincide con
// la suma de todas las coordenadas y’s de los puntos del vector
bool prop2 (const vector<Punto> &v) {
    int size = v.size(), sum_x = 0, sum_y = 0;
    for (int i = 0; i < size; ++i) {
        sum_x += v[i].x;
        sum_y += v[i].y;
    }
    
    return sum_x == sum_y;
}

// Calcula en b el baricentro de los puntos de v, y devuelve un booleano que
// indica si b está o no en el vector v
bool baricentro (const vector<Punto> &v, Punto& b) {
    int size = v.size();
    int i = 0; 
    bool aparece = true;
    while (aparece and i < size) {
        if (v[i].x == b.x and v[i].y == b.y) aparece = false;
        ++i;
    }
	
    return aparece;
}

int main () {
    cout.setf(ios::fixed);
    cout.precision(2);

    int cases;
    while (cin >> cases) {
        vector<Punto> elementos = read_in_vector(cases);
        Punto bar = baricentro2(elementos);

        calcular_imprimir_baricentro(elementos);
        if (not prop1(elementos)) cout << "el vector no cumple la propiedad 1" << endl;
        else if (not prop2(elementos)) cout << "el vector no cumple la propiedad 2" << endl;
        else if (not baricentro(elementos, bar)) cout << "el vector no cumple la propiedad 3" << endl;
        else cout << "vector normalizado" << endl;
    }
}