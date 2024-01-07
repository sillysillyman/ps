#include <iostream>

using namespace std;

int N, M;
int food_size;
int max_food_size = 0;
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
int visited[100][100];
int aisle[100][100];

bool is_inside(int x, int y) { return 0 <= x && x < N && 0 <= y && y < M; }

void dfs(int x, int y) {
  if (visited[x][y] || !aisle[x][y]) return;
  visited[x][y] = 1;
  food_size++;
  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];

    if (is_inside(nx, ny)) dfs(nx, ny);
  }
}

int main() {
  int K;

  cin >> N >> M >> K;
  while (K--) {
    int r, c;

    cin >> r >> c;
    r--, c--;
    aisle[r][c] = 1;
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (!visited[i][j] && aisle[i][j]) {
        food_size = 0;
        dfs(i, j);
        max_food_size = max(max_food_size, food_size);
      }
    }
  }
//   cout << '\n';
//   for (int i = 0; i < N; i++) {
//     for (int j = 0; j < M; j++) {
//       cout << visited[i][j] << ' ';
//     }
//     cout << '\n';
//   }
  cout << max_food_size;
}