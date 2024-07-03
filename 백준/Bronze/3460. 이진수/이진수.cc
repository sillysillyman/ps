#include <cstdio>

int main() {
  int T;

  scanf("%d", &T);
  while (T--) {
    int n, curr_bit = 0;

    scanf("%d", &n);
    while (n) {
      if (n % 2) printf("%d ", curr_bit);
      n /= 2;
      curr_bit++;
    }
  }
}