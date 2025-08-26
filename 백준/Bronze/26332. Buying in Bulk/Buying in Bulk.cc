#include <cstdio>

int main() {
  int n, c, p;
  scanf("%d", &n);
  while (n--) {
    scanf("%d%d", &c, &p);
    printf("%d %d\n%d\n", c, p, (p - 2) * c + 2);
  }
}