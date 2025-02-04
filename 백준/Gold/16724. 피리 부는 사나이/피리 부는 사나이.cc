#include <cstdio>
#include <map>

int N, M;
int p[1'000'000];
char graph[1'000][1'000];
bool visited[1'000][1'000];

int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }

void unite(int x, int y) { p[find(x)] = find(y); }

void dfs(int x, int y) {
  if (visited[x][y]) return;
  visited[x][y] = true;
  if (graph[x][y] == 'U') {
    unite(find(M * x + y), find(M * (x - 1) + y));
    dfs(x - 1, y);
  } else if (graph[x][y] == 'D') {
    unite(find(M * x + y), find(M * (x + 1) + y));
    dfs(x + 1, y);
  } else if (graph[x][y] == 'L') {
    unite(find(M * x + y), find(M * x + y - 1));
    dfs(x, y - 1);
  } else if (graph[x][y] == 'R') {
    unite(find(M * x + y), find(M * x + y + 1));
    dfs(x, y + 1);
  }
}

int main() {
  scanf("%d%d", &N, &M);
  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++) scanf(" %1c", &graph[i][j]);

  for (int i = 0; i < N * M; i++) p[i] = i;
  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++) dfs(i, j);

  std::map<int, int> cnts;
  for (int i = 0; i < N * M; i++) ++cnts[find(i)];
  printf("%zu", cnts.size());
}