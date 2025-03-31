#include <algorithm>
#include <iostream>

using namespace std;

bool is_palindrome(string s) {
  string t = s;
  reverse(t.begin(), t.end());
  return s == t;
}

string add(string s, string t) {
  while (t.length() < s.length()) t = '0' + t;

  int carry = 0;
  string res;
  for (int i = s.length() - 1; i >= 0; i--) {
    int n = (s[i] - '0') + (t[i] - '0') + carry;
    carry = n / 10;
    res = (char)(n % 10 + '0') + res;
  }
  if (carry) res = '1' + res;

  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  string num;
  while (cin >> num && num != "0") {
    for (int i = 0;; i++) {
      if (is_palindrome(add(num, to_string(i)))) {
        cout << i << '\n';
        break;
      }
    }
  }
}