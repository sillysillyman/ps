#include <cstdio>

int main() {
  int a1, a0, c, n0;
  bool success = true;

  scanf("%d%d%d%d", &a1, &a0, &c, &n0);
  if (c < a1)
    puts("0");
  else {
    for (int i = n0; i <= 100; i++) {
      if (a1 * n0 + a0 > c * n0) {
        success = false;
        break;
      }
    }
    printf("%d", success ? 1 : 0);
  }
}