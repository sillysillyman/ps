#include <algorithm>
#include <cstdio>

int graph[40][40];

int main() {
  int R, C, T, cnt = 0;

  scanf("%d%d", &R, &C);
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) scanf("%d", &graph[i][j]);
  }
  scanf("%d", &T);
  for (int i = 0; i < R - 2; i++) {
    for (int j = 0; j < C - 2; j++) {
      int pixels[9] = {
          graph[i][j],     graph[i][j + 1],     graph[i][j + 2],
          graph[i + 1][j], graph[i + 1][j + 1], graph[i + 1][j + 2],
          graph[i + 2][j], graph[i + 2][j + 1], graph[i + 2][j + 2]};
      std::sort(pixels, pixels + 9);
      if (pixels[4] >= T) ++cnt;
    }
  }
  printf("%d", cnt);
}