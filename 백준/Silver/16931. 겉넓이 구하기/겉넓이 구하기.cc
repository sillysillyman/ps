#include <iostream>

using namespace std;

int N, M;
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
int graph[100][100];

bool is_inside(int x, int y) { return 0 <= x && x < N && 0 <= y && y < M; }

int main() {
  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) cin >> graph[i][j];
  }

  int surface_area = 0;

  for (int x = 0; x < N; x++) {
    for (int y = 0; y < M; y++) {
      surface_area += 2;
      for (int i = 0; i < 4; i++) {
        int neighbor_height = 0;
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (is_inside(nx, ny)) neighbor_height = graph[nx][ny];
        surface_area += max(0, graph[x][y] - neighbor_height);
      }
    }
  }
  cout << surface_area;
}