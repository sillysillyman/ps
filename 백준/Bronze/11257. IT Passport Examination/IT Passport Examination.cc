#include <cstdio>

int main() {
  int N, n, a, b, c;
  scanf("%d", &N);
  while (N--) {
    scanf("%d%d%d%d", &n, &a, &b, &c);
    printf("%d %d %s\n", n, a + b + c, a + b + c > 54 && a > 10 && b > 7 && c > 11 ? "PASS" : "FAIL");
  }
}