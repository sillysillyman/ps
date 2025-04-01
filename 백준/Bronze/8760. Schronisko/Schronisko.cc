#include <cstdio>

int main() {
  int Z;
  scanf("%d", &Z);
  while (Z--) {
    int W, K;
    scanf("%d%d", &W, &K);
    printf("%d\n", W * K / 2);
  }
}