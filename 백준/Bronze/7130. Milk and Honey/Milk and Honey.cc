#include <cstdio>

int main() {
  int M, H, N, C, B, s = 0;
  scanf("%d%d%d", &M, &H, &N);
  while (N--) {
    scanf("%d%d", &C, &B);
    s += M * C > H * B ? M * C : H * B;
  }
  printf("%d", s);
}