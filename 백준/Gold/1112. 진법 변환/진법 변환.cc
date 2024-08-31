#include <iostream>

using namespace std;

string res;

int main() {
  bool negative = false;
  int x, b, digit, carry = 0;

  cin >> x >> b;
  if (x < 0) {
    negative = true;
    if (b > 0) x = -x;
  }
  while (x) {
    // cout << "x = " << x << endl;
    // cout << "x % b = " << x % b << endl;
    digit = x % b;
    if (digit >= 0) {
      res = to_string((x % b)) + res;
      //   cout << "res: " << res << endl;
      carry = 0;
    } else {
      if (digit > b) {
        res = to_string(x % b - b) + res;
        carry = 1;
      } else {
        res = to_string(x % b + b) + res;
        // carry = 0;
      }
      //   cout << "res: " << res << endl;
    }
    x /= b;
    x += carry;
    // cout << '\n';
  }
  if (negative && b > 0) res = '-' + res;
  if (res.empty())
    cout << '0';
  else
    cout << res;
}