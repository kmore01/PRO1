/* Program that */

#include <iostream>

using namespace std;

struct Rectangle {
    int x_left, x_right, y_down, y_up;
};

// Procedure that reads a rectangle 
void read(Rectangle &r) {
    cin >> r.x_left >> r.x_right >> r.y_down >> r.y_up;
}

// Function that return 1 if r1 is inside r2, 2 if r2 is inside r1, 3 if none is
// inside the other one but the rectangles intersect, 4 if the rectangles are
// identical, and 0 otherwise
int relationship(const Rectangle &r1, const Rectangle &r2) {
    int veredict;

    if (r1.x_left == r2.x_left and r1.x_right == r2.x_right and r1.y_down == r2.y_down and r1.y_up == r2.y_up) veredict = 4;

    else if (r1.x_left >= r2.x_left and r1.x_right <= r2.x_right and r1.y_down >= r2.y_down and r1.y_up <= r2.y_up) veredict = 1;
    
    else if (r1.x_left <= r2.x_left and r1.x_right >= r2.x_right and r1.y_down <= r2.y_down and r1.y_up >= r2.y_up) veredict = 2;

    else if (r1.y_down > r2.y_up or r2.y_down > r1.y_up or r1.x_left > r2.x_right or r2.x_left > r1.x_right) veredict = 0;

    else veredict = 3;

    return veredict;
}

// Procedure that prints the final veredict according to both rectangles
void print_answer(const Rectangle &r1, const Rectangle &r2) {
    if (relationship(r1, r2) == 1) cout << "the first rectangle is inside the second one" << endl;

    else if (relationship(r1, r2) == 2) cout << "the second rectangle is inside the first one" << endl;

    else if (relationship(r1, r2) == 3) cout << "rectangles intersect" << endl;

    else if (relationship(r1, r2) == 4) cout << "rectangles are identical" << endl;

    else cout << "rectangles do not intersect" << endl;
}

int main () {
    int cases; // natural
    cin >> cases;
    Rectangle input1, input2;
    for (int i = 0; i < cases; ++i) {
        read(input1);
        read(input2);
        print_answer(input1, input2);
    }
}