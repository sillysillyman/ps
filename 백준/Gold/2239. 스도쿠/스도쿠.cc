#include <cstdio>

bool flag = false;
int graph[9][9];

bool is_valid(int x, int y, int num) {
  for (int i = 0; i < 9; i++)
    if (graph[x][i] == num) return false;

  for (int i = 0; i < 9; i++)
    if (graph[i][y] == num) return false;

  int r = 3 * (x / 3);
  int c = 3 * (y / 3);
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      if (graph[r + i][c + j] == num) return false;

  return true;
}

void back_tracking(int x, int y) {
  if (x == 9) {
    flag = true;
    return;
  }
  if (y == 9) {
    back_tracking(x + 1, 0);
    return;
  }
  if (graph[x][y]) {
    back_tracking(x, y + 1);
    return;
  }

  for (int i = 1; i <= 9; i++) {
    if (is_valid(x, y, i)) {
      graph[x][y] = i;
      back_tracking(x, y + 1);
      if (flag) return;
      graph[x][y] = 0;
    }
  }
}

int main() {
  for (int i = 0; i < 9; i++)
    for (int j = 0; j < 9; j++) scanf("%1d", &graph[i][j]);

  back_tracking(0, 0);

  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) printf("%d", graph[i][j]);
    printf("\n");
  }
}