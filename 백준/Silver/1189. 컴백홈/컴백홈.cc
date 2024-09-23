#include <cstdio>
#include <utility>

using namespace std;

int R, C, K, cnt;
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
pair<int, int> src;
pair<int, int> dest;
char graph[5][5];

bool is_inside(int x, int y) { return 0 <= x && x < R && 0 <= y && y < C; }

void dfs(pair<int, int> curr, int depth) {
  if (curr == dest && depth == K) {
    ++cnt;
    return;
  }
  auto [x, y] = curr;
  graph[x][y] = 'T';
  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    if (is_inside(nx, ny) && graph[nx][ny] == '.') dfs({nx, ny}, depth + 1);
  }
  graph[x][y] = '.';
}

int main() {
  scanf("%d %d %d", &R, &C, &K);
  for (int i = 0; i < R; i++)
    for (int j = 0; j < C; j++) scanf(" %1c", &graph[i][j]);
  src = {R - 1, 0};
  dest = {0, C - 1};
  dfs(src, 1);
  printf("%d", cnt);
}