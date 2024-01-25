#include <iostream>

using namespace std;

char castle[50][50];

int main() {
  int N, M;
  int row_cnt = 0;
  int col_cnt = 0;

  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    bool has_guard = false;

    for (int j = 0; j < M; j++) {
      cin >> castle[i][j];
      if (castle[i][j] == 'X') has_guard = true;
    }
    if (!has_guard) row_cnt++;
  }
  for (int j = 0; j < M; j++) {
    bool has_guard = false;

    for (int i = 0; i < N; i++) {
      if (castle[i][j] == 'X') {
        has_guard = true;
        break;
      }
    }
    if (!has_guard) col_cnt++;
  }
  cout << max(row_cnt, col_cnt);
}