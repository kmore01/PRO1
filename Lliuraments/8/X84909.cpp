/* program that prints how many classes are in an hour, how many differents
teachers are in each hour and which is the minimum number of hours of class
where we need to replace current professor with a new one in order to avoid
conflicts */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Struct that contain all the subjects and teachers
struct Slot {
    vector<string> listsubjects;
    vector<string> listteachers;
};

typedef vector<vector<Slot> > TableSlots;

// Function that returns the position in the matrix of a day
int convert_day(string day) {
    int num;
    if (day == "monday") num = 0;
    else if (day == "tuesday") num = 1;
    else if (day == "wednesday") num = 2;
    else if (day == "thursday") num = 3;
    else num = 4;

    return num;
} 

int main() {
    string subject, teacher, day;
    int initial_hour, final_hour, min_hour, max_hour, num_replacements;

    // The size changes!
    TableSlots calendar(24, vector<Slot> (5));

    min_hour = 23;
    max_hour = num_replacements = 0;

    while (cin >> subject) {
        cin >> teacher >> day >> initial_hour >> final_hour;
        // We calculate the maxim hour and minim hour
        if (initial_hour < min_hour) min_hour = initial_hour;
        if (final_hour > max_hour) max_hour = final_hour;
        // We convert the day in an integer to acces the matrix
        int num_day = convert_day(day);

        // We save the subjects and teachers in the TableSlots
        for (int i = initial_hour; i < final_hour; ++i){
            calendar[i][num_day].listsubjects.push_back(subject);
            calendar[i][num_day].listteachers.push_back(teacher);
        }
    }

    /* OUTPUT 1 */
    cout << "number of subjects per slot:" << endl;
    cout << " h    monday   tuesday wednesday  thursday    friday" << endl;
    for(int i = min_hour; i < max_hour; ++i){
        if(i < 10) cout << ' ';
        cout << i;

        for(int j = 0; j < 5; ++j){
            int list_subject_size, digits_subjects;
            digits_subjects = 1;
            list_subject_size = calendar[i][j].listsubjects.size();

            for(int k = list_subject_size; k > 9; k /= 10) ++digits_subjects;

            // Print
            for(int k = 0; k < 10 - digits_subjects; ++k) cout << ' ';
            cout << list_subject_size;
        }
        cout << endl;
    }
    
    /* OUTPUT 2 */
    cout << "number of teachers per slot:" << endl;
    cout << " h    monday   tuesday wednesday  thursday    friday" << endl;
    for(int i = min_hour; i < max_hour; ++i){
        if(i < 10) cout << ' ';
        cout << i;
        for(int j = 0; j < 5; ++j){
            int list_teacher_size, different_teacher, digits_teachers;
            digits_teachers = 1;

            list_teacher_size = calendar[i][j].listteachers.size();

            if(list_teacher_size == 0) different_teacher = 0;
            else different_teacher = 1;

            sort(calendar[i][j].listteachers.begin(), calendar[i][j].listteachers.end());

            for(int k = 1; k < list_teacher_size; ++k){
                if(calendar[i][j].listteachers[k] != calendar[i][j].listteachers[k-1]) ++different_teacher;
            }

            // Replacement is needed
            num_replacements += list_teacher_size - different_teacher;

            for(int k = different_teacher; k > 9; k /= 10) ++digits_teachers;

            // Print
            for(int k = 0; k < 10 - digits_teachers; ++k) cout << ' ';
            cout << different_teacher;  
        }
        cout << endl;
    }

    /* OUTPUT 3*/
    cout << "number of replacements needed to avoid conflicts:" << endl;
    cout << num_replacements << endl;
}