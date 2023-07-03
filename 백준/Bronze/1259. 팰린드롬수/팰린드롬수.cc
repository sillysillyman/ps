#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool is_palindrome(int num) {
    string s = to_string(num);
    string r = to_string(num);
    int len = s.length();

    reverse(r.begin(), r.end());
    for (int i = 0; i < len; i++) {
        if (s[i] == r[i]) continue;
        else return false;
    }
    return true;
}

int main() {
    int num;

    while (1) {
        cin >> num;
        if (num == 0) break;
        if (is_palindrome(num)) cout << "yes" << '\n';
        else cout << "no" << '\n';
    }
}