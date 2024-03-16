#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int R, C;
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
int purifier[2] = {-1, -1};
queue<tuple<int, int, int>> dusts;
int graph[50][50];
int copied[50][50];

bool is_inside(int x, int y) { return 0 <= x && x < R && 0 <= y && y < C; }

void spread() {
  int size = dusts.size();

  while (size--) {
    int cnt = 0;
    auto [x, y, dust] = dusts.front();

    dusts.pop();
    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];

      if (is_inside(nx, ny) && copied[nx][ny] != -1) {
        cnt++;
        graph[nx][ny] += copied[x][y] / 5;
      }
    }
    graph[x][y] -= (copied[x][y] / 5) * cnt;
  }
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) copied[i][j] = graph[i][j];
  }
}

void circulate() {
  graph[purifier[0]][1] = 0;
  for (int i = 2; i < C; i++)
    graph[purifier[0]][i] = copied[purifier[0]][i - 1];
  for (int i = purifier[0] - 1; i >= 0; i--)
    graph[i][C - 1] = copied[i + 1][C - 1];
  for (int i = C - 2; i >= 0; i--) graph[0][i] = copied[0][i + 1];
  for (int i = 1; i < purifier[0]; i++) graph[i][0] = copied[i - 1][0];
  graph[purifier[1]][1] = 0;
  for (int i = 2; i < C; i++)
    graph[purifier[1]][i] = copied[purifier[1]][i - 1];
  for (int i = purifier[1] + 1; i < R; i++)
    graph[i][C - 1] = copied[i - 1][C - 1];
  for (int i = C - 2; i >= 0; i--) graph[R - 1][i] = copied[R - 1][i + 1];
  for (int i = R - 2; i > purifier[1]; i--) graph[i][0] = copied[i + 1][0];
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      copied[i][j] = graph[i][j];
      if (!graph[i][j] || graph[i][j] == -1) continue;
      dusts.push({i, j, graph[i][j]});
    }
  }
}

int main() {
  int T;

  cin >> R >> C >> T;
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      cin >> graph[i][j];
      copied[i][j] = graph[i][j];
      if (graph[i][j] == -1) {
        if (purifier[0] == -1)
          purifier[0] = i;
        else
          purifier[1] = i;
      } else if (graph[i][j])
        dusts.push({i, j, graph[i][j]});
    }
  }
  while (T--) {
    spread();
    circulate();
  }

  int total_dust = 0;

  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      if (!graph[i][j] || graph[i][j] == -1) continue;
      total_dust += graph[i][j];
    }
  }
  cout << total_dust;
}