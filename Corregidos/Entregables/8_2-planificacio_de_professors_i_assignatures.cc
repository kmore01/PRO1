// Entregable: PRO1 2023-2024 Q1 D8_T1_online

#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

typedef vector<string> VS;

struct Slot {
    VS listsubjects;
    VS listteachers;
};

typedef vector<vector<Slot> > TableSlots;

// Pre: s is in weekdays
// Returns the index of s
int get_day_index(const string& s, const VS weekdays) {
    for (int i = 0; i < 6; ++i) {
        if (s == weekdays[i])  return i;
    }
    return 6;
}

// Pre: -
// Post: min_time and max_time have the minimum and maximum hour with lectures
TableSlots build_table(int& min_time, int& max_time, const VS weekdays) {
    min_time = 24;
    max_time = -1;
    TableSlots T(5, vector<Slot>(24));

    string subject, teacher, day;
    int start, end;
    while (cin >> subject >> teacher >> day >> start >> end) {
        int day_index = get_day_index(day, weekdays);
        for (int h = start; h < end; ++h) {
            T[day_index][h].listsubjects.push_back(subject);
            T[day_index][h].listteachers.push_back(teacher);
        }
        if (start < min_time)  min_time = start;
        if (end-1 > max_time)  max_time = end-1;
    }

    return T;
}

// Pre: -
// Writes s right-justified in pad spaces
void print_padding(const string& s, int pad) {
    for (int i = 0; i < pad - s.length(); ++i)  cout << ' ';
    cout << s;
}

// Pre: -
// Converts a number to string and writes it padded
void print_number_padding(int n, int pad) {
    stringstream ss;
    ss << n;
    print_padding(ss.str(), pad);
}

// Pre: -
// Returns the number of unique values in v
int get_unique(VS v) {
    if (v.size() == 0)  return 0;

    int n_unique = 1;
    if (v.size() > 2)  sort(v.begin(), v.end());
    for (int i = 1; i < v.size(); ++i) {
        if (v[i] != v[i-1])  ++n_unique;
    }

    return n_unique;
}

// Pre: -
// Prints the header of the table
void print_header(const VS weekdays, const string& s) {
    cout << "number of " << s << " per slot:" << endl;
    print_padding("h", 2);
    for (int d = 0; d < 5; ++d) {
        print_padding(weekdays[d], 10);
    }
    cout << endl;
}

// Pre: -
// Post: n_replacements has the number of substitutions needed for lectures
// Writes tables of lectures and teachers
void print_tables(int& n_replacements, const TableSlots& T, int min_time, int max_time, const VS weekdays) {
    n_replacements = 0;

    // lectures table:
    print_header(weekdays, "subjects");
    for (int t = min_time; t <= max_time; ++t) {
        print_number_padding(t, 2);
        for (int d = 0; d < 5; ++d) {
            int n_subjects = T[d][t].listsubjects.size();
            print_number_padding(n_subjects, 10);
        }
        cout << endl;
    }

    // teachers table:
    print_header(weekdays, "teachers");
    for (int t = min_time; t <= max_time; ++t) {
        print_number_padding(t, 2);
        for (int d = 0; d < 5; ++d) {
            int n_teachers = get_unique(T[d][t].listteachers);
            n_replacements += T[d][t].listteachers.size() - n_teachers;
            print_number_padding(n_teachers, 10);
        }
        cout << endl;
    }
}

int main() {
    VS weekdays(5);
    weekdays[0] = "monday";
    weekdays[1] = "tuesday";
    weekdays[2] = "wednesday";
    weekdays[3] = "thursday";
    weekdays[4] = "friday";

    int min_time, max_time;
    TableSlots T = build_table(min_time, max_time, weekdays);
    
    int n_replacements;
    print_tables(n_replacements, T, min_time, max_time, weekdays);
    cout << "number of replacements needed to avoid conflicts:" << endl;
    cout << n_replacements << endl;
}
