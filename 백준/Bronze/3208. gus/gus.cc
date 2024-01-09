#include <iostream>

using namespace std;

int M, N;
int chocolate[100][100];

bool is_eaten_all() {
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      if (!chocolate[i][j]) return false;
    }
  }
  return true;
}

int main() {
  int cnt = 0;

  cin >> M >> N;

  int i = 0, j = 0;
  pair<int, int> direction;
  pair<int, int> right = {0, 1};
  pair<int, int> left = {0, -1};
  pair<int, int> up = {-1, 0};
  pair<int, int> down = {1, 0};

  direction = right;
  while (!is_eaten_all()) {
    chocolate[i][j] = 1;
    if ((0 <= i + direction.first && i + direction.first < M &&
         0 <= j + direction.second && j + direction.second < N) &&
        !chocolate[i + direction.first][j + direction.second]) {
      i += direction.first;
      j += direction.second;
    } else {
      if (direction == right)
        direction = down;
      else if (direction == left)
        direction = up;
      else if (direction == up)
        direction = right;
      else if (direction == down)
        direction = left;
      cnt++;
    }
  }
  cout << cnt - 1;
}