#include <iostream>

using namespace std;

int grid[15][15];

int main() {
  int N, M, K;

  cin >> N >> M >> K;

  pair<int, int> via = {0, 0};

  while (K > M) {
    K -= M;
    via.first++;
  }
  via.second = max(0, K - 1);
  for (int i = 0; i <= via.first; i++) {
    for (int j = 0; j <= via.second; j++) {
      if (i == 0 || j == 0)
        grid[i][j] = 1;
      else
        grid[i][j] = grid[i - 1][j] + grid[i][j - 1];
    }
  }
  for (int i = via.first; i < N; i++) {
    for (int j = via.second; j < M; j++) {
      if (i == via.first || j == via.second)
        grid[i][j] = grid[via.first][via.second];
      else
        grid[i][j] = grid[i - 1][j] + grid[i][j - 1];
    }
  }
  cout << grid[N - 1][M - 1];
}