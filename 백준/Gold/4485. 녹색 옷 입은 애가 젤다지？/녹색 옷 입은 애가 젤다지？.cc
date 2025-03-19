#include <cstdio>
#include <queue>
#include <tuple>

using namespace std;

const int INF = 125 * 9;
int N;
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
int graph[125][125];
int costs[125][125];

bool is_inside(int x, int y) { return 0 <= x && x < N && 0 <= y && y < N; }

int dijkstra() {
  priority_queue<tuple<int, int, int>> pq;
  pq.push({-costs[0][0], 0, 0});

  while (!pq.empty()) {
    auto [cost, x, y] = pq.top();
    pq.pop();

    if (costs[x][y] < -cost) continue;

    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];

      if (is_inside(nx, ny) && graph[nx][ny] - cost < costs[nx][ny]) {
        costs[nx][ny] = graph[nx][ny] - cost;
        pq.push({-costs[nx][ny], nx, ny});
      }
    }
  }

  return costs[N - 1][N - 1];
}

int main() {
  for (int t = 1;; t++) {
    scanf("%d", &N);
    if (!N) break;
    for (int i = 0; i < N; i++)
      for (int j = 0; j < N; j++) scanf("%d", &graph[i][j]);

    for (int i = 0; i < N; i++)
      for (int j = 0; j < N; j++) costs[i][j] = INF;
    costs[0][0] = graph[0][0];
    printf("Problem %d: %d\n", t, dijkstra());
  }
}