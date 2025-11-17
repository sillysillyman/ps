#include <cstdio>

int main() {
  int H, W, N, M;
  scanf("%d%d%d%d", &H, &W, &N, &M);
  printf("%d", (H / ++N + !!(H % N)) * (W / ++M + !!(W % M)));
}