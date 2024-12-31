#include <cstdio>

int paper[1'001][1'001];

int main() {
  int N;
  scanf("%d", &N);

  for (int n = 1; n <= N; n++) {
    int x, y, w, h;
    scanf("%d%d%d%d", &x, &y, &w, &h);

    for (int i = x; i < x + w; i++)
      for (int j = y; j < y + h; j++) paper[i][j] = n;
  }
  for (int n = 1; n <= N; n++) {
    int cnt = 0;

    for (int i = 0; i < 1'001; i++)
      for (int j = 0; j < 1'001; j++) cnt += paper[i][j] == n;

    printf("%d\n", cnt);
  }
}