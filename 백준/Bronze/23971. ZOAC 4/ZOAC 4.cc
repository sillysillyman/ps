#include <cstdio>

int main() {
  int H, W, N, M;
  scanf("%d%d%d%d", &H, &W, &N, &M);
  printf("%d", (H / (N + 1) + !!(H % (N + 1))) * (W / (M + 1) + !!(W % (M + 1))));
}