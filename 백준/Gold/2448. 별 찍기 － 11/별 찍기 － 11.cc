#include <iostream>

using namespace std;

char graph[3'072][6'143];

void fill_stars(int row, int col, int size) {
  if (size == 3) {
    for (int i = row; i < row + 3; i++) {
      for (int j = col; j < col + 5; j++) {
        if ((i == row && j == col + 2) ||
            (i == row + 1 && (j == col + 1 || j == col + 3)) || (i == row + 2))
          graph[i][j] = '*';
      }
    }
  } else {
    fill_stars(row, col + size / 2, size / 2);
    fill_stars(row + size / 2, col, size / 2);
    fill_stars(row + size / 2, col + size, size / 2);
  }
}

int main() {
  int N;

  cin >> N;
  fill(&graph[0][0], &graph[N - 1][2 * N], ' ');
  fill_stars(0, 0, N);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 2 * N - 1; j++) cout << graph[i][j];
    cout << '\n';
  }
}