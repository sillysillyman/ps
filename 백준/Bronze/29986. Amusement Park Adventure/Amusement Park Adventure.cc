#include <cstdio>

int N, H, A, n;

int main() {
  scanf("%d%d", &N, &H);
  while (N--) scanf("%d", &A), n += A <= H;
  printf("%d", n);
}