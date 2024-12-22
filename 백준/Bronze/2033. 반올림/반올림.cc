#include <cstdio>
#include <cstring>

int main() {
  char N[9];

  scanf("%s", N);

  int carry = 0;
  for (int i = strlen(N) - 1; i >= 0; i--) {
    int digit = N[i] - '0' + carry;

    if (!i) {
      if (digit > 9) {
        carry = 1;
        N[i] = '0';
      } else {
        carry = 0;
        N[i] = digit + '0';
      }
    } else {
      if (digit < 5)
        carry = 0;
      else
        carry = 1;
      N[i] = '0';
    }
  }
  carry ? printf("1%s", N) : printf("%s", N);
}