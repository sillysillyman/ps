#include <cstdio>

int main() {
  int N, T, B, t = 0, b = 5e3;
  scanf("%d", &N);
  while (N--) {
    scanf("%d%d", &T, &B);
    if (T > t) t = T;
    if (B < b) b = B;
  }
  printf("%d", t * b % 7 + 1);
}