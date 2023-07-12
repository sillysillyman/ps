#include <iostream>
#include <cmath>
#include <string>

using namespace std;

string cantor(string s) {
    int len = s.length();
    string space;

    if (len == 1) return s;
    for (int i = 0; i < len/3; i++) space.push_back(' ');
    s = cantor(s.substr(0, len/3)) + space + cantor(s.substr(len/3, len/3));
    return s;
}

int main() {
    int N;

    while (cin >> N) {
        string s;
        int len;

        if (N == 0) len = 1;
        else len = pow(3, N);
        for (int i = 0; i < len; i++) s.push_back('-');
        cout << cantor(s) << endl;
    }
}