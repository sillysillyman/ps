#include <iostream>

using namespace std;

unsigned int MAX_VAL = 0xFFFFFFFF;

long long convert_to_decimal(string& num, int base) {
  if (base == 1) {
    for (char c : num)
      if (c != '1') return -1;
    return num.length();
  }

  long long res = 0, power = 1;
  for (auto it = num.rbegin(); it != num.rend(); it++) {
    int digit = (isdigit(*it) ? *it - '0' : *it - 'a' + 10);
    if (digit >= base) return -1;

    if (power > MAX_VAL) return -1;
    res += 1LL * digit * power;
    if (res > MAX_VAL) return -1;
    power *= base;
  }

  return res < 1 ? -1 : res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;

  cin >> N;
  while (N--) {
    char op, eq;
    string X, Y, Z, bases;

    cin >> X >> op >> Y >> eq >> Z;
    for (int i = 1; i <= 36; i++) {
      long long x = convert_to_decimal(X, i);
      long long y = convert_to_decimal(Y, i);
      long long z = convert_to_decimal(Z, i);

      if (x < 0 || y < 0 || z < 0) continue;
      if ((op == '+' && x + y <= MAX_VAL && x + y == z) ||
          (op == '-' && x > y && x - y == z) ||
          (op == '*' && x * y <= MAX_VAL && x * y == z) ||
          (op == '/' && y != 0 && x % y == 0 && x / y == z))
        bases += i == 36 ? '0' : i < 10 ? '0' + i : 'a' + i - 10;
    }
    cout << (bases.empty() ? "invalid" : bases) << '\n';
  }
}