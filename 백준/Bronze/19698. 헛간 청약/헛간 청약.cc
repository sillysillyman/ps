#include <cstdio>

int main() {
  int N, W, H, L, n;
  scanf("%d%d%d%d", &N, &W, &H, &L);
  n = W / L * (H / L);
  printf("%d", n > N ? N : n);
}