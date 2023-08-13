#include <iostream>

using namespace std;

int lcs[1001][1001] = {};

int main() {
    string s, t;

    cin >> s >> t;
    for (int i = 0; i < s.length(); i++) {
        for (int j = 0; j < t.length(); j++) {
            if (s[i] == t[j]) lcs[i + 1][j + 1] = lcs[i][j] + 1;
            else lcs[i + 1][j + 1] = max(lcs[i][j + 1], lcs[i + 1][j]);
        }
    }
    cout << lcs[s.length()][t.length()];
}