#include <iostream>

using namespace std;

int mat[101][101];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int r, c;
  while (cin >> r >> c && (r || c)) {
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        char c;
        cin >> c;
        mat[i][j] = c == '#';
      }
    }

    int cnt = 0;
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        if (!mat[i][j]) continue;
        if (!i && !j)
          cnt += !(mat[0][1] || mat[1][0] || mat[1][1]);
        else if (!i && j == c - 1)
          cnt += !(mat[0][c - 2] || mat[1][c - 2] || mat[1][c - 1]);
        else if (i == r - 1 && !j)
          cnt += !(mat[r - 2][0] || mat[r - 2][1] || mat[r - 1][1]);
        else if (i == r - 1 && j == c - 1)
          cnt += !(mat[r - 2][c - 2] || mat[r - 2][c - 1] || mat[r - 1][c - 2]);
        else {
          int flag = 1;
          for (int x = i - 1; x < i + 2; x++) {
            for (int y = j - 1; y < j + 2; y++) {
              if (x == i && y == j) continue;
              if (mat[x][y]) flag = 0;
            }
          }
          cnt += flag;
        }
      }
    }
    cout << cnt << '\n';
  }
}