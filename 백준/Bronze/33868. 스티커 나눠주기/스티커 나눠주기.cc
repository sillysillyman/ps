#include <cstdio>

int N, T, B, t, b = 5e3;

int main() {
  scanf("%d", &N);
  while (N--) {
    scanf("%d%d", &T, &B);
    if (T > t) t = T;
    if (B < b) b = B;
  }
  printf("%d", t * b % 7 + 1);
}