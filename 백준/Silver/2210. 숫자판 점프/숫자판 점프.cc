#include <cstdio>
#include <set>

using namespace std;

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
int graph[5][5];
set<int> nums;

bool is_inside(int x, int y) { return 0 <= x && x < 5 && 0 <= y && y < 5; }

void dfs(int x, int y, int num, int depth) {
  if (depth == 6) {
    nums.insert(num);
    return;
  }
  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];

    if (!is_inside(nx, ny)) continue;
    dfs(nx, ny, 10 * num + graph[nx][ny], depth + 1);
  }
}

int main() {
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) scanf("%d", &graph[i][j]);
  }
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) dfs(i, j, graph[i][j], 1);
  }
  printf("%d", nums.size());
}