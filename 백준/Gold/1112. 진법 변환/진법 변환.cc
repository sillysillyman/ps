#include <iostream>

using namespace std;

string res;

int main() {
  bool negative = false;
  int x, b, carry = 0;

  cin >> x >> b;
  if (x < 0 && b > 0) {
    negative = true;
    x = -x;
  }
  while (x) {
    if (int digit = x % b; digit >= 0) {
      res = to_string((x % b)) + res;
      carry = 0;
    } else {
      if (digit > b)
        res = to_string(x % b - b) + res;
      else
        res = to_string(x % b + b) + res;
      carry = 1;
    }
    x /= b;
    x += carry;
  }
  if (negative) res = '-' + res;
  if (res.empty())
    cout << '0';
  else
    cout << res;
}