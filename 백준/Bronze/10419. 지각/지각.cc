#include <cmath>
#include <cstdio>

int main() {
  int T, d;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &d);
    printf("%d\n", (int)((-1 + sqrt(1 + 4 * d)) / 2));
  }
}