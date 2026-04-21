#include <cstdio>

int n, k, p, t, c;

int main() {
  scanf("%d%d", &n, &k);
  while (n--) {
    scanf("%d", &t);
    c += p - t >= k;
    p = t;
  }
  printf("%d", c);
}