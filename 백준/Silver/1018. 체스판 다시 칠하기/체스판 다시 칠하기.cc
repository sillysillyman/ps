#include <iostream>

using namespace std;

int board[50][50] = {};

int get_cnt(int i, int j) {
  int black_started_cnt = 0, white_started_cnt = 0;

  for (int k = i; k < i + 8; k++) {
    for (int l = j; l < j + 8; l++) {
      if ((k + l) % 2 == 0) {
        if (board[k][l] == -1) {
          white_started_cnt++;
        } else if (board[k][l] == 1) {
          black_started_cnt++;
        } else
          continue;
      } else {
        if (board[k][l] == 1) {
          white_started_cnt++;
        } else if (board[k][l] == -1) {
          black_started_cnt++;
        } else
          continue;
      }
    }
  }
  return black_started_cnt > white_started_cnt ? white_started_cnt
                                               : black_started_cnt;
}

int main() {
  int N, M;

  cin >> N >> M;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      char square;

      cin >> square;
      if (square == 'B')
        board[i][j] = -1;
      else if (square == 'W')
        board[i][j] = 1;
      else
        continue;
    }
  }

  int min_cnt = 50 * 50;

  for (int i = 0; i <= N - 8; i++) {
    for (int j = 0; j <= M - 8; j++) {
      if (int cnt = get_cnt(i, j); cnt < min_cnt) min_cnt = cnt;
    }
  }
  cout << min_cnt;
}