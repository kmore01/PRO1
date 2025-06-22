// Programa que ordena paises segun cual se considera con menos desigualdad
// segun el coeficiente de Gini

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Info {
    string country_name;
    double gini;
};

// Funcion para calcular la tasa de desigualdad en un pais segun el coeficiente
// de gini
//pre: quintile_data represents a country income by quintile info
//post: returns the gini coef corresponding to quintile_data   
double gini_coef(const vector<double>& quintile_data) {
    double s1 = (quintile_data[1] - quintile_data[0]) +
    (quintile_data[2] - quintile_data[0]) +
    (quintile_data[3] - quintile_data[0]) +
    (quintile_data[4] - quintile_data[0]);

    double s2 = (quintile_data[2] - quintile_data[1]) + (quintile_data[3] - quintile_data[1]) + (quintile_data[4] - quintile_data[1]);

    double s3 = (quintile_data[3] - quintile_data[2])
    + (quintile_data[4] - quintile_data[2]);

    double s4 = (quintile_data[4] - quintile_data[3]);

    return (s1 + s2 + s3 + s4) / 500;
}

// Funcion para guardar el pais y guardar la desigualdad
vector<Info> guardar_info() {
    int num_paises; // entero > 0
    cin >> num_paises;
    vector<Info> VPaises(num_paises);
    vector<double> quintile(5);

    for (int i = 0; i < num_paises; ++i) {
        cin >> VPaises[i].country_name;
        cin >> quintile[0] >> quintile[1] >> quintile[2] >> quintile[3]
            >> quintile[4];
        VPaises[i].gini = gini_coef(quintile);
    } 

    return VPaises;
}

// Procedimiento para imprimir los paises y su tasa de desigualdad
void imprimir(const vector<Info>& paises) {
    for (int i = 0; i < paises.size(); ++i) {
        cout << paises[i].country_name << ' ' << paises[i].gini << endl;
    }
}

// Funcion que ordenada dos paises segun su tasa de desigualdad y si son
// iguales, segun el orden lexicografico
bool order(Info &a, Info &b) {
    if (a.gini != b.gini) return a.gini < b.gini;
    else return a.country_name < b.country_name;
}

int main () {
    cout.setf(ios::fixed);
    cout.precision(4);

    vector<Info> VPaises = guardar_info();
    // Ordenamos el vector
    sort (VPaises.begin(), VPaises.end(), order);
    imprimir(VPaises);
}