#include <cstdio>
#include <cstring>

int main() {
  char N[9];
  scanf("%s", N);

  int carry = 0;
  for (int i = strlen(N) - 1; i >= 0; i--) {
    int digit = N[i] - '0' + carry;

    carry = i ? (digit >= 5) : (digit > 9);
    N[i] = i ? '0' : (digit % 10 + '0');
  }
  if (carry) printf("1");
  printf("%s", N);
}