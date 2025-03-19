#include <cstdio>
#include <deque>
#include <tuple>

using namespace std;

int n;
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
bool visited[50][50];
int graph[50][50];

bool is_inside(int x, int y) { return 0 <= x && x < n && 0 <= y && y < n; };

int bfs() {
  deque<tuple<int, int, int>> dq;
  dq.push_back({0, 0, 0});
  visited[0][0] = 1;

  while (!dq.empty()) {
    auto [x, y, cnt] = dq.front();
    dq.pop_front();

    if (x == n - 1 && y == n - 1) return cnt;

    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];

      if (is_inside(nx, ny) && !visited[nx][ny]) {
        graph[nx][ny] ? dq.push_front({nx, ny, cnt})
                      : dq.push_back({nx, ny, cnt + 1});
        visited[nx][ny] = 1;
      }
    }
  }

  return 0;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) scanf("%1d", &graph[i][j]);

  printf("%d", bfs());
}