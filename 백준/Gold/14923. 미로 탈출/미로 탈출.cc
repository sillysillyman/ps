#include <cstdio>
#include <queue>
#include <tuple>

using namespace std;

struct Pos {
  int x, y;

  bool operator==(const Pos &other) const {
    return x == other.x && y == other.y;
  }
};

int N, M;
Pos src, dest;
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
int graph[1'000][1'000];
bool visited[1'000][1'000][2];

bool is_inside(Pos p) { return 0 <= p.x && p.x < N && 0 <= p.y && p.y < M; }

int bfs() {
  queue<tuple<Pos, int, bool>> q;
  q.push({src, 0, false});
  visited[src.x][src.y][0] = 1;

  while (!q.empty()) {
    auto [curr, cnt, flag] = q.front();
    q.pop();

    if (curr == dest) return cnt;

    for (int i = 0; i < 4; i++) {
      Pos next = {curr.x + dx[i], curr.y + dy[i]};
      if (!is_inside(next) || visited[next.x][next.y][flag]) continue;
      if (!graph[next.x][next.y]) {
        q.push({next, cnt + 1, flag});
        visited[next.x][next.y][flag] = 1;
      } else if (graph[next.x][next.y] && !flag) {
        q.push({next, cnt + 1, true});
        visited[next.x][next.y][1] = 1;
      }
    }
  }

  return -1;
}

int main() {
  scanf("%d%d", &N, &M);
  scanf("%d%d", &src.x, &src.y);
  scanf("%d%d", &dest.x, &dest.y);
  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++) scanf("%d", &graph[i][j]);
  --src.x, --src.y, --dest.x, --dest.y;
  printf("%d", bfs());
}