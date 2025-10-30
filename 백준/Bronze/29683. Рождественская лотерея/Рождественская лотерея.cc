#include <cstdio>

int n, A, a, s;

int main() {
  scanf("%d%d", &n, &A);
  while (n--) scanf("%d", &a), s += a / A;
  printf("%d", s);
}