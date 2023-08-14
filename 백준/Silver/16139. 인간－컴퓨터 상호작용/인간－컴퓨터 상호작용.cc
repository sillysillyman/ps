#include <iostream>

using namespace std;

int accumulated[200000];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    string S;
    int q;
    char a;
    int l, r;

    cin >> S;
    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> a >> l >> r;
        for (int i = 0; i < S.length(); i++) {
            if (i == 0 && S[i] != a) accumulated[i] = 0;
            else if (i == 0 && S[i] == a) accumulated[i] = 1;
            else if (S[i] == a) accumulated[i] = accumulated[i - 1] + 1;
            else accumulated[i] = accumulated[i - 1];
        }
        if (l == 0) cout << accumulated[r] << '\n';
        else cout << accumulated[r] - accumulated[l - 1] << '\n';
    }
}
// 0 1 2 3 4 5 6 7 8 9 10 11 12
// s e u n g j a e h w  a  n  g