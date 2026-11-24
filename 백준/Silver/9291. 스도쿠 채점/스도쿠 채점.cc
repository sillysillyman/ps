#include <cstdio>

int graph[9][9];

bool isCorrect() {
  for (int k = 0; k < 9; k++) {
    bool row[10] = {}, col[10] = {}, box[10] = {};
    for (int m = 0; m < 9; m++) {
      int r = graph[k][m];
      int c = graph[m][k];
      int b = graph[k / 3 * 3 + m / 3][k % 3 * 3 + m % 3];
      if (row[r] || col[c] || box[b])
        return false;
      row[r] = col[c] = box[b] = true;
    }
  }
  return true;
}

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; t++) {
    for (int i = 0; i < 9; i++)
      for (int j = 0; j < 9; j++)
        scanf("%d", &graph[i][j]);
    printf("Case %d: %s\n", t, isCorrect() ? "CORRECT" : "INCORRECT");
  }
}