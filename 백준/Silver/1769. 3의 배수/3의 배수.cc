#include <iostream>
#include <string>

using namespace std;

int cnt = 0;

string add(string x, string y) {
    int carry = 0;
    int len, y_len;
    string res = "";

    if (y.length() > x.length()) swap(x, y);
    len = x.length();
    y_len = y.length();
    for (int i = 0; i < len - y_len; i++) y.insert(0, "0");
    for (int i = len - 1; i >= 0; i--) {
        int n = (x[i] - '0') + (y[i] - '0');
        
        if (carry) n++;
        carry = n/10;
        res.insert(0, to_string(n%10));
    }
    if (carry) res.insert(0, "1");
    while (res[0] == '0') res = res.substr(1);
    return res;
}

string sum_digits(string x) {
    int len = x.length();
    string res(1, x[len - 1]);

    cnt++;
    for (int i = len - 2; i >= 0; i--) {
        string s;

        s = x[i];
        res = add(res, s);
        // cout << "s: " << s << endl;
        // cout << "res: " << res << endl;
    }
    // cout << "res: " << res << endl;
    if (res.length() > 1) res = sum_digits(res);
    return res;
}

int main() {
    string X, Y;

    cin >> X;
    if (X.length() > 1) Y = sum_digits(X);
    else Y = X;
    cout << cnt << '\n';

    int n = stoi(Y);

    if (n%3) cout << "NO";
    else cout << "YES";
}