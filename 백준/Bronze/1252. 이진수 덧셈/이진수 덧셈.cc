#include <iostream>

using namespace std;

string add(string a, string b) {
  if (a.length() < b.length()) swap(a, b);

  int len = a.length();
  int b_len = b.length();

  for (int i = 0; i < len - b_len; i++) b = "0" + b;

  int carry = 0;
  int digit;
  string ret = "";

  for (int i = len - 1; i >= 0; i--) {
    digit = (a[i] - '0') + (b[i] - '0') + carry;
    carry = digit / 2;
    digit %= 2;
    ret = to_string(digit) + ret;
  }
  if (carry) ret = "1" + ret;
  if (ret.length() != 1) {
    while (ret[0] == '0' && ret.length() > 1) ret = ret.substr(1);
  }
  return ret;
}

int main() {
  string a, b;

  cin >> a >> b;
  cout << add(a, b);
}