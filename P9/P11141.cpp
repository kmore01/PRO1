// program that calculates the maximum, minimum and average of students

#include <iostream>
#include <vector>

using namespace std;

struct Student {
    int idn;
    string name;
    double mark; // The mark is a value between 0 and 10, or -1 that represents NP
    bool repeater;
}; 

// procedure that calculates the maximum, minimum and average
void information(const vector<Student>& stu, double& min, double& max, double& avg) {
    min = 11;
    max = 0;
    avg = 0;
    int count = 0;
    for (int i = 0; i < stu.size(); ++i) {
        if (stu[i].mark != -1 and not stu[i].repeater) { // si l'estudiant s'ha presentat i no es repetidor
            avg += stu[i].mark; // accedim a la nota del estudiant
            if (stu[i].mark < min) min = stu[i].mark;
            if (stu[i].mark > max) max = stu[i].mark;
            ++count;
        }
    }
    avg /= count;
    if (count == 0) min = max = avg = -1; // si no hi ha cap que s'hagi presentat o tots son repetidors
}

// procedure that reads the students and prints the maximum, minimum and average
void read_in_vector(vector<Student> v_stud) {
    double min, max, avg;
    min = max = avg = 0;
    int idn;
    while (cin >> idn) {
        string name;
        double mark;
        string repeater;
        cin >> name >> mark >> repeater;
        Student mystudent;
        mystudent.idn = idn;
        mystudent.mark = mark;
        if (repeater == "si") mystudent.repeater = true;
        else mystudent.repeater = false;
        v_stud.push_back(mystudent);
        information(v_stud, min, max, avg);
        cout << "Max:" << max << ' ';
        cout << "Min:" << min << ' ';
        cout << "Avg:" << avg << endl;
    }
}

int main () {
    vector<Student> v_stud;
    read_in_vector(v_stud);
}