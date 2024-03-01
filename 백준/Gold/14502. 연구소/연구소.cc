#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M;
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
int lab[8][8];
bool visited[8][8];
int graph[8][8];
vector<pair<int, int>> vacant_spaces;

void init() {
  fill(&visited[0][0], &visited[N - 1][M], false);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) graph[i][j] = lab[i][j];
  }
}

bool is_inside(int x, int y) { return 0 <= x && x < N && 0 <= y && y < M; }

void bfs() {
  queue<pair<int, int>> q;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (graph[i][j] == 2) {
        visited[i][j] = true;
        q.push({i, j});
      }
    }
  }
  while (!q.empty()) {
    auto [x, y] = q.front();

    graph[x][y] = 2;
    q.pop();
    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];

      if (is_inside(nx, ny) && !visited[nx][ny] && graph[nx][ny] == 0) {
        visited[nx][ny] = true;
        q.push({nx, ny});
      } 
    }
  }
}

int count_safe_area() {
  int cnt = 0;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (graph[i][j] == 0) cnt++;
    }
  }
  return cnt;
}

int main() {
  int max_cnt = 0;

  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> lab[i][j];
       graph[i][j] = lab[i][j];
    }
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (lab[i][j] == 0) vacant_spaces.push_back({i, j});
    }
  }
//   for (auto vacant_space : vacant_spaces) {
//     cout << vacant_space.first << ' ' << vacant_space.second << endl;
//   }

  int size = vacant_spaces.size();

  for (int i = 0; i < size; i++) {
    for (int j = i + 1; j < size; j++) {
      for (int k = j + 1; k < size; k++) {
        init();
        graph[vacant_spaces[i].first][vacant_spaces[i].second] = 1;
        graph[vacant_spaces[j].first][vacant_spaces[j].second] = 1;
        graph[vacant_spaces[k].first][vacant_spaces[k].second] = 1;
        bfs();
        if (int cnt = count_safe_area(); max_cnt < cnt) {
          max_cnt = cnt;
        //   cout << "cnt = " << cnt << '\n';
        //   for (int i = 0; i < N; i++) {
        //     for (int j = 0; j < M; j++) cout << graph[i][j] << ' ';
        //     cout << '\n';
        //   }
        }
      }
    }
  }
  cout << max_cnt;
}