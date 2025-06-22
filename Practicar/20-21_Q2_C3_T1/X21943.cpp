// Programa que genera un listado de los participantes ordenados según varios
// criterios

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Funcion que guarda las respuestas correctas del test
vector<int> read_right_answers(int num_preguntas) {
    vector<int> respuestas_correctas(num_preguntas);
    for (int i = 0; i < num_preguntas; ++i) {
        cin >> respuestas_correctas[i];
    }

    return respuestas_correctas;
}

struct Student {
    string name;
    int right;
    int wrong;
};

// Funcion para guardar los estudiantes en un vector con sus aciertos y fallos
vector<Student> get_info_test(vector<int> respuestas, int num_alumnos) {
    vector<Student> VStud(num_alumnos);
    for (int i = 0; i < num_alumnos; ++i) {
        int r = 0, w = 0;
        cin >> VStud[i].name;
        for (int j = 0; j < respuestas.size(); ++j) {
            int respuesta;
            cin >> respuesta;
            if (respuesta == respuestas[j]) ++r;
            else if (respuesta != 0) ++w;
        }
        VStud[i].right = r;
        VStud[i].wrong = w;
    }

    return VStud;
}

// Funcion que ordena a dos estudiantes segun la nota, fallos y nombre
bool cmp(Student &a, Student &b) {
    // Cada respuesta acertada cuenta 2 puntos, una incorrect resta 1 punto
    if (a.right * 2 - a.wrong != b.right * 2 - b.wrong) return a.right * 2 - a.wrong > b.right * 2 - b.wrong; 
    else if (a.wrong != b.wrong) return a.wrong < b.wrong;
    else return a.name < b.name;
}

// Procedimiento para imprimir los alumnos con numero de aciertos y fallos
void write_results(vector<Student> ans) {
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i].name << ' ' << ans[i].right << ' ' << ans[i].wrong
             << endl;
    }
}

int main() {
    int m;
    cin >> m;
    vector<int> answer = read_right_answers(m);
    int n;
    cin >> n;
    vector<Student> v = get_info_test(answer, n);
    sort(v.begin(), v.end(), cmp);
    write_results(v);
}