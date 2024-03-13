#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int N;
int bridge = 10'000;
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
bool visited[100][100];
pair<int, bool> graph[100][100];

bool is_inside(int x, int y) { return 0 <= x && x < N && 0 <= y && y < N; }

void bfs(int x, int y, int island) {
  queue<tuple<int, int, int>> q;

  q.push({x, y, 0});
  while (!q.empty()) {
    auto [x, y, dist] = q.front();

    q.pop();
    if (graph[x][y].first && graph[x][y].first != island) {
      bridge = min(bridge, dist - 1);
      break;
    }
    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];

      if (is_inside(nx, ny) && !visited[nx][ny] &&
          graph[nx][ny].first != island) {
        visited[nx][ny] = true;
        q.push({nx, ny, dist + 1});
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> graph[i][j].first;
      if (graph[i][j].first)
        graph[i][j].second = true;
      else
        graph[i][j].second = false;
    }
  }

  int island = 0;
  queue<pair<int, int>> q;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (visited[i][j] || !graph[i][j].first) continue;
      island++;
      visited[i][j] = true;
      q.push({i, j});
      while (!q.empty()) {
        int cnt = 0;
        auto [x, y] = q.front();

        q.pop();
        graph[x][y].first = island;
        for (int k = 0; k < 4; k++) {
          int nx = x + dx[k];
          int ny = y + dy[k];

          if (is_inside(nx, ny) && graph[nx][ny].first) {
            cnt++;
            if (visited[nx][ny]) continue;
            visited[nx][ny] = true;
            q.push({nx, ny});
          }
        }
        if (!(x == 0 || x == N - 1 || y == 0 || y == N - 1) && cnt == 4)
          graph[x][y].second = false;
        else if ((x == 0 || x == N - 1) && !(y == 0 || y == N - 1) && cnt == 3)
          graph[x][y].second = false;
        else if (!(x == 0 || x == N - 1) && (y == 0 || y == N - 1) && cnt == 3)
          graph[x][y].second = false;
        else if ((x == 0 || x == N - 1) && (y == 0 || y == N - 1) && cnt == 2)
          graph[x][y].second = false;
      }
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (graph[i][j].second) {
        fill(&visited[0][0], &visited[N - 1][N], false);
        bfs(i, j, graph[i][j].first);
      }
    }
  }
  cout << bridge;
}