#include <deque>
#include <iostream>
#include <queue>

using namespace std;

struct Pos {
  int x, y;

  bool operator==(const Pos& pos) { return x == pos.x && y == pos.y; }
};

int N;
pair<int, int> dirs[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
bool visited[101][101];
bool board[101][101];
queue<pair<int, char>> cmds;
deque<Pos> snake;

bool is_inside(int x, int y) { return 1 <= x && x <= N && 1 <= y && y <= N; }

int main() {
  int K, L;

  cin >> N >> K;
  fill(&visited[1][1], &visited[N][N + 1], false);
  fill(&board[1][1], &board[N][N + 1], false);
  for (int row, col, i = 0; i < K; i++) {
    cin >> row >> col;
    board[row][col] = true;
  }
  cin >> L;
  for (int i = 0; i < L; i++) {
    char dir;
    int time;

    cin >> time >> dir;
    cmds.push({time, dir});
  }

  int timer = 0;
  Pos dir = {0, 1};

  snake.push_front({1, 1});
  while (true) {
    auto [x, y] = snake.front();

    visited[x][y] = true;
    // cout << '\n';
    // cout << "timer: " << timer << '\n';
    // for (int i = 1; i <= N; i++) {
    //   for (int j = 1; j <= N; j++) cout << !!visited[i][j] << ' ';
    //   cout << '\n';
    // }
    // cout << '\n';
    if (!cmds.empty()) {
      auto [time, cmd] = cmds.front();

      if (time == timer) {
        if (cmd == 'L') {
          if (dir == Pos{-1, 0}) dir = {0, -1};
          else if (dir == Pos{0, -1}) dir = {1, 0};
          else if (dir == Pos{0, 1}) dir = {-1, 0};
          else if (dir == Pos{1, 0}) dir = {0, 1};
        } else if (cmd == 'D') {
          if (dir == Pos{-1, 0}) dir = {0, 1};
          else if (dir == Pos{0, -1}) dir = {-1, 0};
          else if (dir == Pos{0, 1}) dir = {1, 0};
          else if (dir == Pos{1, 0}) dir = {0, -1};
        }
        cmds.pop();
      }
    }

    int nx = x + dir.x;
    int ny = y + dir.y;

    if (!is_inside(nx, ny) || visited[nx][ny]) {
      timer++;
      break;
    } else {
      visited[nx][ny] = true;
      snake.push_front({nx, ny});
      if (board[nx][ny]) board[nx][ny] = false;
      else {
        visited[snake.back().x][snake.back().y] = false;
        snake.pop_back();
      }
    }
    timer++;
  }
  cout << timer;
}