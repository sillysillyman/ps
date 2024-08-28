#include <cstdio>

int main() {
  int E, S, M, year = 1;

  scanf("%d%d%d", &E, &S, &M);
  for (int e = 1, s = 1, m = 1;; year++) {
    if (e == E && s == S && m == M) break;
    e = e % 15 + 1;
    s = s % 28 + 1;
    m = m % 19 + 1;
  }
  printf("%d", year);
}