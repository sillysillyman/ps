#include <iostream>
#include <algorithm>

using namespace std;

bool is_palindrome(string str) {
    bool res = true;
    int len = str.length();

    for (int i = 0; i < len/2; i++) {
        if (str[i] != str[len - i - 1]) res = false;
    }
    return res;
} 

int main() {
    int len;
    int res = -1;
    string S;

    cin >> S;
    len = S.length();
    // if (is_palindrome(S)) {
    //     cout << S.length();
    //     return 0;
    // }
    for (int i = 1; i <= len/2; i++) {
        string s, t, u;

        s = S.substr(len - i, i);
        t = S.substr(len - 2*i, i);
        if (len >= 2*i + 1) u = S.substr(len - 2*i - 1, i);
        reverse(t.begin(), t.end());
        reverse(u.begin(), u.end());
        // cout << "s: " << s << ", t: " << t << ", u: " << u << endl;
        if (s == u) {
            res = 2*len - 2*i - 1;
            // cout << "res: " << res << endl;
        }
        else if (s == t) {
            res = 2*len - 2*i;
            // cout << "res: " << res << endl;
        }
    }
    if (res == -1) res = 2*len - 1;
    // cout << endl;
    cout << res;
}