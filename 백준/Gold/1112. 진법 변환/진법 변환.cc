#include <cstdio>

char res[32];

int main() {
  bool negative = false;
  int x, b, idx = 0, carry = 0;

  scanf("%d%d", &x, &b);
  if (x < 0 && b > 0) {
    negative = true;
    x = -x;
  }
  do {
    int digit = x % b;
    if (digit >= 0)
      carry = 0;
    else {
      digit -= b;
      carry = 1;
    }
    res[idx++] = '0' + (digit < 0 ? digit + b : digit);
    x /= b;
    x += carry;
  } while (x);
  if (negative) res[idx++] = '-';
  while (idx--) printf("%c", res[idx]);
}