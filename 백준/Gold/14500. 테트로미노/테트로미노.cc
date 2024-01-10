#include <iostream>

using namespace std;

int N, M;
int board[500][500];

bool is_inside(int x, int y) { return 0 <= x && x < N && 0 <= y && y < M; }

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int max_score = 0;

  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) cin >> board[i][j];
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      int i_score;

      if (is_inside(i - 3, j)) {
        i_score =
            board[i - 3][j] + board[i - 2][j] + board[i - 1][j] + board[i][j];
        max_score = max(max_score, i_score);
      }
      if (is_inside(i, j - 3)) {
        i_score =
            board[i][j - 3] + board[i][j - 2] + board[i][j - 1] + board[i][j];
        max_score = max(max_score, i_score);
      }
      if (is_inside(i, j + 3)) {
        i_score =
            board[i][j] + board[i][j + 1] + board[i][j + 2] + board[i][j + 3];
        max_score = max(max_score, i_score);
      }
      if (is_inside(i + 3, j)) {
        i_score =
            board[i][j] + board[i + 1][j] + board[i + 2][j] + board[i + 3][j];
        max_score = max(max_score, i_score);
      }

      int o_score;

      if (is_inside(i - 1, j - 1)) {
        o_score = board[i - 1][j - 1] + board[i - 1][j] + board[i][j - 1] +
                  board[i][j];
        max_score = max(max_score, o_score);
      }
      if (is_inside(i - 1, j + 1)) {
        o_score = board[i - 1][j] + board[i - 1][j + 1] + board[i][j] +
                  board[i][j + 1];
        max_score = max(max_score, o_score);
      }
      if (is_inside(i + 1, j - 1)) {
        o_score = board[i][j - 1] + board[i][j] + board[i + 1][j - 1] +
                  board[i + 1][j];
        max_score = max(max_score, o_score);
      }
      if (is_inside(i + 1, j + 1)) {
        o_score = board[i][j] + board[i][j + 1] + board[i + 1][j] +
                  board[i + 1][j + 1];
        max_score = max(max_score, o_score);
      }

      int l_score, s_score, t_score;

      if (is_inside(i - 2, j - 1)) {
        l_score = board[i - 2][j - 1] + board[i - 1][j - 1] + board[i][j - 1] +
                  board[i][j];
        s_score = board[i - 2][j - 1] + board[i - 1][j - 1] + board[i - 1][j] +
                  board[i][j];
        t_score = board[i - 2][j] + board[i - 1][j - 1] + board[i - 1][j] +
                  board[i][j];
        max_score = max(max_score, max(l_score, max(s_score, t_score)));
      }
      if (is_inside(i - 2, j + 1)) {
        l_score = board[i - 2][j + 1] + board[i - 1][j + 1] + board[i][j] +
                  board[i][j + 1];
        s_score = board[i - 2][j + 1] + board[i - 1][j] + board[i - 1][j + 1] +
                  board[i][j];
        t_score = board[i - 2][j] + board[i - 1][j] + board[i - 1][j + 1] +
                  board[i][j];
        max_score = max(max_score, max(l_score, max(s_score, t_score)));
      }
      if (is_inside(i - 1, j - 2)) {
        l_score = board[i - 1][j - 2] + board[i - 1][j - 1] + board[i - 1][j] +
                  board[i][j];
        s_score = board[i - 1][j - 2] + board[i - 1][j - 1] + board[i][j - 1] +
                  board[i][j];
        t_score = board[i - 1][j - 1] + board[i][j - 2] + board[i][j - 1] +
                  board[i][j];
        max_score = max(max_score, max(l_score, max(s_score, t_score)));
      }
      if (is_inside(i - 1, j + 2)) {
        l_score = board[i - 1][j] + board[i - 1][j + 1] + board[i - 1][j + 2] +
                  board[i][j];
        s_score = board[i - 1][j + 1] + board[i - 1][j + 2] + board[i][j] +
                  board[i][j + 1];
        t_score = board[i - 1][j + 1] + board[i][j] + board[i][j + 1] +
                  board[i][j + 2];
        max_score = max(max_score, max(l_score, max(s_score, t_score)));
      }
      if (is_inside(i + 1, j - 2)) {
        l_score = board[i][j] + board[i + 1][j - 2] + board[i + 1][j - 1] +
                  board[i + 1][j];
        s_score = board[i][j - 1] + board[i][j] + board[i + 1][j - 2] +
                  board[i + 1][j - 1];
        t_score = board[i][j - 2] + board[i][j - 1] + board[i][j] +
                  board[i + 1][j - 1];
        max_score = max(max_score, max(l_score, max(s_score, t_score)));
      }
      if (is_inside(i + 1, j + 2)) {
        l_score = board[i][j] + board[i + 1][j] + board[i + 1][j + 1] +
                  board[i + 1][j + 2];
        s_score = board[i][j] + board[i][j + 1] + board[i + 1][j + 1] +
                  board[i + 1][j + 2];
        t_score = board[i][j] + board[i][j + 1] + board[i][j + 2] +
                  board[i + 1][j + 1];
        max_score = max(max_score, max(l_score, max(s_score, t_score)));
      }
      if (is_inside(i + 2, j - 1)) {
        l_score = board[i][j - 1] + board[i][j] + board[i + 1][j - 1] +
                  board[i + 2][j - 1];
        s_score = board[i][j] + board[i + 1][j - 1] + board[i + 1][j] +
                  board[i + 2][j - 1];
        t_score = board[i][j] + board[i + 1][j - 1] + board[i + 1][j] +
                  board[i + 2][j];
        max_score = max(max_score, max(l_score, max(s_score, t_score)));
      }
      if (is_inside(i + 2, j + 1)) {
        l_score = board[i][j] + board[i][j + 1] + board[i + 1][j + 1] +
                  board[i + 2][j + 1];
        s_score = board[i][j] + board[i + 1][j] + board[i + 1][j + 1] +
                  board[i + 2][j + 1];
        t_score = board[i][j] + board[i + 1][j] + board[i + 1][j + 1] +
                  board[i + 2][j];
        max_score = max(max_score, max(l_score, max(s_score, t_score)));
      }
    }
  }
  cout << max_score;
}