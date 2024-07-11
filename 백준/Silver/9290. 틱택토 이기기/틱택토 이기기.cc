#include <iostream>

using namespace std;

char board[3][3];

void print_board(int t) {
  cout << "Case " << t << ":\n";
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) cout << board[i][j];
    cout << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;

  cin >> T;
  for (int t = 1; t <= T; t++) {
    bool flag = false;
    char player;

    for (int i = 0; i < 3; i++) {
      string line;

      cin >> line;
      for (int j = 0; j < 3; j++) board[i][j] = line[j];
    }
    cin >> player;
    for (int i = 0; i < 3; i++) {
      if ((board[i][0] == player && board[i][1] == player) ||
          (board[i][0] == player && board[i][2] == player) ||
          (board[i][1] == player && board[i][2] == player)) {
        board[i][0] = player;
        board[i][1] = player;
        board[i][2] = player;
        print_board(t);
        flag = true;
      }
    }
    if (flag) continue;
    for (int j = 0; j < 3; j++) {
      if ((board[0][j] == player && board[1][j] == player) ||
          (board[0][j] == player && board[2][j] == player) ||
          (board[1][j] == player && board[2][j] == player)) {
        board[0][j] = player;
        board[1][j] = player;
        board[2][j] = player;
        print_board(t);
        flag = true;
      }
    }
    if (flag) continue;
    if ((board[0][0] == player && board[1][1] == player) ||
        (board[0][0] == player && board[2][2] == player) ||
        (board[1][1] == player && board[2][2] == player)) {
      board[0][0] = player;
      board[1][1] = player;
      board[2][2] = player;
      print_board(t);
    } else if ((board[0][2] == player && board[1][1] == player) ||
               (board[0][2] == player && board[2][0] == player) ||
               (board[1][1] == player && board[2][0] == player)) {
      board[0][2] = player;
      board[1][1] = player;
      board[2][0] = player;
      print_board(t);
    }
  }
}