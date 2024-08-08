#include <iostream>

using namespace std;

int count_carry(string& a, string& b) {
  int cnt = 0, carry = 0;

  if (a.length() < b.length()) swap(a, b);

  int len_diff = a.length() - b.length();
  for (int i = 0; i < len_diff; i++) b = '0' + b;

  int len = a.length();
  for (int i = len - 1; i >= 0; i--) {
    int digit = a[i] - '0' + b[i] - '0' + carry;

    if (digit > 9) {
      ++cnt;
      carry = 1;
    } else
      carry = 0;
  }
  return cnt;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  while (true) {
    string a, b;

    cin >> a >> b;
    if (a == "0" && b == "0") break;
    cout << count_carry(a, b) << '\n';
  }
}