#include <cstdio>

int N, M, cnt;
bool visited[50][50];
char graph[50][50];

void dfs(int x, int y, char c) {
  if (x < 0 || x >= N || y < 0 || y >= M) return;
  if (graph[x][y] != c || visited[x][y]) return;
  visited[x][y] = 1;
  if (c == '-') {
    dfs(x, y - 1, c);
    dfs(x, y + 1, c);
  } else {
    dfs(x - 1, y, c);
    dfs(x + 1, y, c);
  }
}

int main() {
  scanf("%d%d", &N, &M);
  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++)
      scanf(" %c", &graph[i][j]);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (visited[i][j]) continue;
      cnt++;
      dfs(i, j, graph[i][j]);
    }
  }
  printf("%d", cnt);
}