#include <iostream>

using namespace std;

int main() {
  bool is_white = true;
  int cnt = 0;
  char board[8][8];

  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      cin >> board[i][j];
      if (is_white && board[i][j] == 'F') cnt++;
      if (j != 7) is_white = !is_white;
    }
  }
  cout << cnt;
}