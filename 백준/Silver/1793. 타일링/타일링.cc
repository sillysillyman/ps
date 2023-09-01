#include <iostream>
#include <string>

using namespace std;

string dp[251] = {};

string add(string a, string b) {
    string ret = "";
    
    if (a.length() < b.length()) swap(a, b);

    int len = a.length();
    int b_len = b.length();

    for (int i = 0; i < len - b_len; i++) b = "0" + b;

    int carry = 0;

    for (int i = len - 1; i >= 0; i--) {
        int c = (a[i] - '0') + (b[i] - '0') + carry;

        if (c > 9) {
            c %= 10;
            carry = 1;
        } else carry = 0;
        ret = to_string(c) + ret;
    }
    if (carry) ret  = "1" + ret;
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    dp[0] = "1";
    dp[1] = "1";
    dp[2] = "3";
    for (int i = 3; i <= 250; i++) dp[i] = add(dp[i - 1], add(dp[i - 2], dp[i - 2]));
    while (cin >> n) cout << dp[n] << '\n';
}