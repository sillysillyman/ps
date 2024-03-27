#include <iostream>
#include <queue>

using namespace std;

struct Pos {
  int x, y;
};

struct Compare {
  bool operator()(const pair<int, Pos>& a, const pair<int, Pos>& b) {
    if (a.first == b.first) {
      if (a.second.x == b.second.x) return a.second.y > b.second.y;
      return a.second.x > b.second.x;
    }
    return a.first > b.first;
  }
};

int N, timer = 0, shark_size = 2, cnt = 2;
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
bool visited[20][20];
int graph[20][20];
Pos shark;

bool is_inside(int x, int y) { return 0 <= x && x < N && 0 <= y && y < N; }

bool bfs(Pos src) {
  priority_queue<pair<int, Pos>, vector<pair<int, Pos>>, Compare> pq;

  visited[src.x][src.y] = true;
  pq.push({0, src});
  while (!pq.empty()) {
    auto [time, pos] = pq.top();
    auto [x, y] = pos;

    pq.pop();
    if (graph[x][y] > 0 && graph[x][y] < shark_size) {
      graph[x][y] = 0;
      shark = {x, y};
      if (!(--cnt)) cnt = ++shark_size;
      timer += time;
      return true;
    }
    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];

      if (is_inside(nx, ny) && !visited[nx][ny] &&
          graph[nx][ny] <= shark_size) {
        visited[nx][ny] = true;
        pq.push({time + 1, {nx, ny}});
      }
    }
  }
  return false;
}

int main() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> graph[i][j];
      if (graph[i][j] == 9) {
        shark = {i, j};
        graph[i][j] = 0;
      }
    }
  }
  while (bfs(shark)) fill(&visited[0][0], &visited[N - 1][N], false);
  cout << timer;
}