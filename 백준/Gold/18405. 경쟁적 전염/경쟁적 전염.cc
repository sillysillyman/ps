#include <algorithm>
#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int N, K;
int S, X, Y;
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
int visited[200][200];
int graph[200][200];

bool is_inside(int x, int y) { return 0 <= x && x < N && 0 <= y && y < N; }

void bfs() {
  queue<tuple<int, int, int>> q;
  vector<pair<int, pair<int, int>>> viruses;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (graph[i][j]) viruses.push_back({graph[i][j], {i, j}});
    }
  }
  sort(viruses.begin(), viruses.end(), [](auto a, auto b) -> bool {
    if (a.first == b.first) {
      if (a.second.first == b.second.first)
        return a.second.second < b.second.second;
      return a.second.first < b.second.first;
    }
    return a.first < b.first;
  });
  for (auto virus : viruses) {
    visited[virus.second.first][virus.second.second] = virus.first;
    q.push({virus.second.first, virus.second.second, 0});
  }

  int second = 0;

  while (!q.empty()) {
    auto [x, y, depth] = q.front();

    // cout << "(" << x << ", " << y << ")\n";
    q.pop();
    if (depth == S) continue;
    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];

      if (is_inside(nx, ny) && !visited[nx][ny]) {
        visited[nx][ny] = visited[x][y];
        q.push({nx, ny, depth + 1});
      }
    }
  }
}

int main() {
  cin >> N >> K;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) cin >> graph[i][j];
  }
  cin >> S >> X >> Y;
  bfs();
//   cout << '\n';
//   for (int i = 0; i < N; i++) {
//     for (int j = 0; j < N; j++) cout << visited[i][j] << ' ';
//     cout << '\n';
//   }
  cout << visited[X - 1][Y - 1];
}