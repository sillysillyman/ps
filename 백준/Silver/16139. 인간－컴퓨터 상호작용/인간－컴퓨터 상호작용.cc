#include <iostream>
#include <map>

using namespace std;

map<int, map<char, int>> m;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    string S;
    int q;
    char a;
    int l, r;

    cin >> S;
    cin >> q;
    for (int i = 0; i < S.length(); i++) {
        if (i == 0) m[i][S[i]]++;
        else {
            m[i] = m[i - 1];
            m[i][S[i]]++;
        }
    }
    // for (auto i : m) {
    //     cout << i.first << " = {";
    //     for (auto j : i.second) {
    //         cout << j.first << ": " << j.second << ", ";
    //     }
    //     cout << "}\n";
    // }
    for (int i = 0; i < q; i++) {
        cin >> a >> l >> r;
        if (l == 0) cout << m[r][a] << '\n';
        else cout << m[r][a] - m[l - 1][a] << '\n';
    }
}
// 0 1 2 3 4 5 6 7 8 9 10 11 12
// s e u n g j a e h w  a  n  g