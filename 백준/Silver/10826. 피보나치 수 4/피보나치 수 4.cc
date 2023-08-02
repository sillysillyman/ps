#include <iostream>
#include <string>

using namespace std;

string add(string x, string y) {
    int len = y.length();
    int carry = 0;
    string res = "";

    if (x.length() < len) {
        int x_len = x.length();

        for (int i = 0; i < len - x_len; i++) x.insert(0, "0");
    }
    for (int i = len - 1; i >= 0; i--) {
        int n = (x[i] - '0') + (y[i] - '0');

        if (carry) n++;
        carry = n/10;
        n %= 10;
        res.insert(0, to_string(n));
    }
    if (carry) res.insert(0, "1");
    return res;
}

int main() {
    int n;
    string dp[10001];

    cin >> n;
    dp[0] = "0";
    dp[1] = "1";
    for (int i = 2; i <= n; i++) dp[i] = add(dp[i - 2], dp[i - 1]);
    cout << dp[n];
}