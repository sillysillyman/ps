#include <cstdio>

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
bool paper[101][101];

int main() {
  int n;
  scanf("%d", &n);
  while (n--) {
    int x, y;
    scanf("%d%d", &x, &y);
    for (int i = x; i < x + 10; i++)
      for (int j = y; j < y + 10; j++) paper[i][j] = 1;
  }

  int p = 0;
  for (int i = 0; i < 100; i++)
    for (int j = 0; j < 100; j++)
      if (paper[i][j])
        for (int k = 0; k < 4; k++) p += !paper[i + dx[k]][j + dy[k]];
  printf("%d", p);
}