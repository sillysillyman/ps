#include <cstdio>
#include <deque>
#include <tuple>

using namespace std;

const int INF = 10'000;
int N, M;
int dx[4] = {-1, 0, 0, 1}, dy[4] = {0, -1, 1, 0};
int graph[100][100];
int dists[100][100];

bool is_inside(int x, int y) { return 0 <= x && x < M && 0 <= y && y < N; }

int main() {
  scanf("%d%d", &N, &M);
  fill(&dists[0][0], &dists[M - 1][N], INF);
  for (int i = 0; i < M; i++)
    for (int j = 0; j < N; j++) scanf("%1d", &graph[i][j]);

  deque<tuple<int, int, int>> dq;
  dq.push_back({0, 0, 0});
  dists[0][0] = 0;
  while (!dq.empty()) {
    auto [x, y, dist] = dq.front();

    dq.pop_front();
    if (dist > dists[x][y]) continue;
    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i], ny = y + dy[i];

      if (is_inside(nx, ny)) {
        if (int next_dist = dist + graph[nx][ny]; next_dist < dists[nx][ny]) {
          dists[nx][ny] = next_dist;
          if (graph[nx][ny])
            dq.push_back({nx, ny, next_dist});
          else
            dq.push_front({nx, ny, next_dist});
        }
      }
    }
  }
  printf("%d", dists[M - 1][N - 1]);
}