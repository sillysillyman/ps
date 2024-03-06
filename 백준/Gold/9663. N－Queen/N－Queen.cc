#include <iostream>

using namespace std;

int N;
int cnt = 0;
int board[15];

bool is_promising(int level) {
  for (int i = 0; i < level; i++) {
    if (board[i] == board[level] || abs(board[i] - board[level]) == level - i)
      return false;
  }
  return true;
}

void n_queen(int n) {
  if (n == N) cnt++;
  for (int i = 0; i < N; i++) {
    board[n] = i;
    if (is_promising(n)) n_queen(n + 1);
  }
}

int main() {
  cin >> N;
  n_queen(0);
  cout << cnt;
}