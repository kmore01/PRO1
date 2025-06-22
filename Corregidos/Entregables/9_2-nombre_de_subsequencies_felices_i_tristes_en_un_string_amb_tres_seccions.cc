// Entregable: PRO1 2023-2024 Q1 D9_T1_online

#include <iostream>
#include <string>

using namespace std;

// Pre: s is formed with three different characters c1,c2,c3, and is of the form c1...c1c2...c2c3...c3.
// Post: n1, n2, n3 are the number of occurrences of c1, c2, c3 in s, respectively.
void numberOccurrences(const string &s, int &n1, int &n2, int &n3) {
    // s: 0,..., i1-1, i1, ..., i2-1, i2, ... s.length()-1
    n1 = n2 = n3 = 0;

    // search of i1:
    int start = 0;
    int end = s.length()-1;
    int i1 = (start+end)/2;
    while (s[i1] == s[0] or s[i1] == s[s.length()-1] or s[i1] == s[i1-1]) {
        if (s[i1] == s[0])  start = i1+1;
        else  end = i1-1;
        i1 = (start+end)/2;
    }

    // search of i2:
    start = i1+1;
    end = s.length()-1;
    int i2 = (start+end)/2;
    while (s[i2] != s[s.length()-1] or s[i2] == s[i2-1]) {
        if (s[i2] != s[s.length()-1])  start = i2+1;
        else  end = i2-1;
        i2 = (start+end)/2;
    }

    n1 = i1;
    n2 = i2-i1;
    n3 = s.length()-i2;
}


// Pre: s begins with one or more occurrences of a character c1, followed by one or more
//      occurrences of a character c2, followed by one or more occurrences of a character c3,
//      and there are no more characters in s.
//      moreover, either c1c2c3 = ":-)" or c1c2c3 = "(-:" or c1c2c3 = ":-(" or c1c2c3 = ")-:".
// Post: If c1c2c3 = ":-)" or c1c2c3 = "(-:", the function returns the number of happy subsequences.
//       If c1c2c3 = ":-(" or c1c2c3 = ")-:", the function returns the number of sad subsequences.
int numberHappyOrSadSubsequences(const string &s) {
    int n1, n2, n3;
    numberOccurrences(s, n1, n2, n3);
    return n1*n2*n3;
}
