#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

struct Pos {
  int x, y;

  bool operator==(const Pos& other) const {
    return x == other.x && y == other.y;
  }
};

int K, W, H;
Pos src, dest;
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
int horse_dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int horse_dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
bool graph[200][200];
bool visited[200][200][31];

bool is_inside(int x, int y) { return 0 <= x && x < H && 0 <= y && y < W; }

int bfs(Pos src, Pos dest) {
  queue<tuple<Pos, int, int>> q;

  visited[src.x][src.y][0] = true;
  q.push({src, 0, 0});
  while (!q.empty()) {
    auto [pos, k, cnt] = q.front();
    auto [x, y] = pos;

    q.pop();
    if (pos == dest) return cnt;
    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];

      if (is_inside(nx, ny) && !graph[nx][ny] && !visited[nx][ny][k]) {
        visited[nx][ny][k] = true;
        q.push({{nx, ny}, k, cnt + 1});
      }
    }
    if (k == K) continue;
    for (int i = 0; i < 8; i++) {
      int nx = x + horse_dx[i];
      int ny = y + horse_dy[i];

      if (is_inside(nx, ny) && !graph[nx][ny] && !visited[nx][ny][k + 1]) {
        visited[nx][ny][k + 1] = true;
        q.push({{nx, ny}, k + 1, cnt + 1});
      }
    }
  }
  return -1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> K >> W >> H;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) cin >> graph[i][j];
  }
  src = {0, 0};
  dest = {H - 1, W - 1};
  cout << bfs(src, dest);
}