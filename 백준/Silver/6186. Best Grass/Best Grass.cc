#include <cstdio>

int R, C, cnt;
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
char graph[100][100];

int main() {
  scanf("%d%d", &R, &C);
  for (int i = 0; i < R; i++)
    for (int j = 0; j < C; j++) scanf(" %c", &graph[i][j]);
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      if (graph[i][j] == '.') continue;
      ++cnt;
      for (int k = 0; k < 4; k++) {
        int nx = i + dx[k];
        int ny = j + dy[k];

        if (0 <= nx && nx < R && 0 <= ny && ny < C) graph[nx][ny] = '.';
      }
    }
  }
  printf("%d", cnt);
}