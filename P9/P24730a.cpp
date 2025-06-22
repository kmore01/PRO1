// program that prints the sorted list of the teachers from best to worst

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Teacher {
    string name;
    int candies;
    int carrots;
};

// function that orders teacher A and teacher B
bool order(const Teacher &A, const Teacher &B) {
    if (A.candies != B.candies)
        return A.candies > B.candies;
    else {
        if (A.carrots != B.carrots)
            return A.carrots > B.carrots;
        else {
            if (A.name.size() != B.name.size())
                return A.name.size() < B.name.size();
            else
                return A.name < B.name;
        }
    }
}

int main() {
    int cases;
    cin >> cases;
    for (int k = 0; k < cases; ++k) {
        int numTeacher;
        cin >> numTeacher;
        vector<Teacher> teachers(numTeacher);
        // we create a vector for all the teachers
        for (int i = 0; i < numTeacher; ++i) {
            cin >> teachers[i].name >> teachers[i].candies >>
                teachers[i].carrots;
        }
        // we order the vector to print it
        sort(teachers.begin(), teachers.end(), order);
        for (int i = 0; i < numTeacher; ++i) {
            cout << teachers[i].name << endl;
        }
        cout << endl;
    }
}