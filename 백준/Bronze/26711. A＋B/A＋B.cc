#include <iostream>

using namespace std;

string add(string a, string b) {
  if (a.length() < b.length()) swap(a, b);

  int len = a.length();
  int b_len = b.length();

  for (int i = 0; i < len - b_len; i++) b = "0" + b;

  int num;
  int carry = 0;
  string ret = "";

  for (int i = len - 1; i >= 0; i--) {
    num = (a[i] - '0') + (b[i] - '0') + carry;
    carry = num / 10;
    num %= 10;
    ret = to_string(num) + ret;
  }
  if (carry) ret = "1" + ret;
  return ret;
}

int main() {
  string a, b;

  cin >> a >> b;
  cout << add(a, b);
}