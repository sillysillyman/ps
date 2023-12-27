#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int M, N, K;
int cnt = 0;
int area;
int graph[100][100] = {};
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
vector<int> areas;

bool is_inside(int x, int y) { return 0 <= x && x < N && 0 <= y && y < M; }

void dfs(int x, int y) {
  if (!is_inside(x, y) || graph[x][y]) return;
  graph[x][y] = 1;
  area++;

  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];

    dfs(nx, ny);
  }
}

int main() {
  cin >> M >> N >> K;
  for (int i = 0; i < K; i++) {
    pair<int, int> pos1, pos2;

    cin >> pos1.first >> pos1.second >> pos2.first >> pos2.second;
    for (int j = pos1.first; j < pos2.first; j++) {
      for (int k = pos1.second; k < pos2.second; k++) graph[j][k] = 1;
    }
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (graph[i][j] == 0) {
        area = 0;
        dfs(i, j);
        areas.push_back(area);
        cnt++;
      }
    }
  }
  sort(areas.begin(), areas.end());
  cout << cnt << '\n';
  for (auto area : areas) cout << area << ' ';
}