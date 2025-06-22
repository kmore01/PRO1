/* program that prints which is the avarage length (L) of a sequence of words
and for each word => L prints also the most frequent letter, in case of ties
the smallest in lexicographic order */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// function that saves words in a vector
vector<string> read_in_vector(int size) {
    vector<string> V(size);
    for (int i = 0; i < size; ++i) {
        cin >> V[i]; // lowercase letters
    }
    return V;
}

// function that calculates how many letters are in a string
int num_letters(vector<string> a) {
    int size = a.size(), count_letters = 0;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < a[i].size(); ++j) {
            // we do +1 to the count until the word finishes
            ++count_letters;
        }
    }
    return count_letters;
}

// function that calculates the most frequent letter of a string
char most_frequent_letter(const string& s) {
    // we create a vector with all the characters of the string
    vector<char> char_list(s.begin(), s.end());
    // we order the vector in ascendant order to be easy to found the letters
    sort(char_list.begin(), char_list.end());
    int count_temporal_letter = 1, count_letter_max = 0;
    
    // we inicializate the previous letter to not count it in the first itineration
    char prev_letter = '-', most_frequent_letter = '-'; 
    int size_w = s.size();
    for (int i = 0; i < size_w; ++i) {
        if (prev_letter == char_list[i]) ++count_temporal_letter;
        else count_temporal_letter = 1;

        // because of the vector is ordered, there is no reason to compare if the new letter < last letter (lexicographicaly)
        if (count_letter_max < count_temporal_letter) {
            count_letter_max = count_temporal_letter;
            most_frequent_letter = char_list[i];
        }
        prev_letter = char_list[i];
    }
    return most_frequent_letter;
}

int main () {
    cout.setf(ios::fixed);
    cout.precision(2);

    int size; // natural > 0
    cin >> size;
    vector<string> sequence = read_in_vector(size);
    double avarage_length = double(num_letters(sequence)) / size;
    cout << avarage_length << endl;

    for (int i = 0; i < size; ++i) {
        if (sequence[i].size() >= avarage_length) cout << sequence[i] << ": "
        << most_frequent_letter(sequence[i]) << endl;
    }
}