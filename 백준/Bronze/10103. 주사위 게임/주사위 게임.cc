#include <cstdio>

int main() {
  int n, A = 100, B = 100;

  scanf("%d", &n);
  while (n--) {
    int a, b;

    scanf("%d%d", &a, &b);
    if (a < b)
      A -= b;
    else if (a > b)
      B -= a;
  }
  printf("%d\n%d", A, B);
}