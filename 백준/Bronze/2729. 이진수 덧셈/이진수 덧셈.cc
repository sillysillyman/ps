#include <iostream>

using namespace std;

string binary_add(string a, string b) {
  if (a.length() < b.length()) swap(a, b);

  int len_gap = a.length() - b.length();
  for (int i = 0; i < len_gap; i++) b = '0' + b;

  int carry = 0;
  string sum;
  for (int bit, i = a.length() - 1; i >= 0; i--) {
    bit = a[i] - '0' + b[i] - '0' + carry;
    carry = bit / 2;
    bit %= 2;
    sum = to_string(bit) + sum;
  }
  if (carry) sum = '1' + sum;
  while (sum[0] == '0' && sum.length() > 1) sum = sum.substr(1);
  return sum;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;

  cin >> T;
  while (T--) {
    string a, b;

    cin >> a >> b;
    cout << binary_add(a, b) << '\n';
  }
}