#include <iostream>

using namespace std;

int N, M;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
char field[100][100];
int visited[100][100];

bool is_inside(int x, int y) { return 0 <= x && x < M && 0 <= y && y < N; }

int dfs(int x, int y, char team) {
  if (visited[x][y] || !is_inside(x, y) || field[x][y] != team) return 0;

  int team_size = 1;

  visited[x][y] = 1;
  for (int i = 0; i < 4; i++) team_size += dfs(x + dx[i], y + dy[i], team);
  return team_size;
}

int main() {
  int white_team_power = 0, blue_team_power = 0;

  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) cin >> field[i][j];
  }
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      int white_team_size, blue_team_size;

      if (field[i][j] == 'W') {
        white_team_size = dfs(i, j, 'W');
        white_team_power += white_team_size * white_team_size;
      } else if (field[i][j] == 'B') {
        blue_team_size = dfs(i, j, 'B');
        blue_team_power += blue_team_size * blue_team_size;
      }
    }
  }
  cout << white_team_power << ' ' << blue_team_power;
}