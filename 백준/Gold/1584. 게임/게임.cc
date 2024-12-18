#include <algorithm>
#include <cstdio>
#include <deque>
#include <tuple>

using namespace std;

struct Tuple {
  int x, y, cost;
};

const int INF = 250'000;
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
int graph[501][501];
int costs[501][501];

bool is_inside(int x, int y) { return 0 <= x && x < 501 && 0 <= y && y < 501; }

int main() {
  int N, M, X1, X2, Y1, Y2;

  fill(&costs[0][0], &costs[500][501], INF);
  scanf("%d", &N);
  while (N--) {
    scanf("%d%d%d%d", &X1, &Y1, &X2, &Y2);
    for (int i = min(X1, X2); i <= max(X1, X2); i++)
      for (int j = min(Y1, Y2); j <= max(Y1, Y2); j++) graph[i][j] = 1;
  }
  scanf("%d", &M);
  while (M--) {
    scanf("%d%d%d%d", &X1, &Y1, &X2, &Y2);
    for (int i = min(X1, X2); i <= max(X1, X2); i++)
      for (int j = min(Y1, Y2); j <= max(Y1, Y2); j++) graph[i][j] = 2;
  }

  deque<Tuple> dq;
  dq.push_back({0, 0, 0});
  costs[0][0] = 0;

  while (!dq.empty()) {
    auto [x, y, cost] = dq.front();
    dq.pop_front();

    if (cost > costs[x][y]) continue;

    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i], ny = y + dy[i];

      if (is_inside(nx, ny) && graph[nx][ny] != 2) {
        int next_cost = cost + graph[nx][ny];

        if (next_cost < costs[nx][ny]) {
          costs[nx][ny] = next_cost;
          if (graph[nx][ny])
            dq.push_back({nx, ny, next_cost});
          else
            dq.push_front({nx, ny, next_cost});
        }
      }
    }
  }
  printf("%d", costs[500][500] == INF ? -1 : costs[500][500]);
}