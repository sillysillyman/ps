#include <cstdio>

int main() {
  int Z, W, K;
  scanf("%d", &Z);
  while (Z--) {
    scanf("%d%d", &W, &K);
    printf("%d\n", W * K / 2);
  }
}