#include <cstdio>
#include <queue>
#include <set>
#include <tuple>

using namespace std;

struct Pos {
  int x, y;

  bool operator==(const Pos& other) const {
    return x == other.x && y == other.y;
  }

  bool operator<(const Pos& other) const {
    return x == other.x ? y < other.y : x < other.x;
  }
};

int N, M;
Pos red, blue;
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
char graph[10][10];
set<pair<Pos, Pos>> visited;

int bfs(Pos src_red, Pos src_blue) {
  queue<tuple<Pos, Pos, int>> q;
  q.push({src_red, src_blue, 0});
  visited.insert({src_red, src_blue});

  while (!q.empty()) {
    auto [red, blue, cnt] = q.front();
    q.pop();

    if (cnt == 10) continue;

    for (int i = 0; i < 4; i++) {
      bool red_flag = false, blue_flag = false;
      Pos nred = red, nblue = blue;

      while (dx[i] && graph[nred.x + dx[i]][nred.y] != '#') {
        nred.x += dx[i];
        if (graph[nred.x][nred.y] == 'O') red_flag = true;
      }
      while (dy[i] && graph[nred.x][nred.y + dy[i]] != '#') {
        nred.y += dy[i];
        if (graph[nred.x][nred.y] == 'O') red_flag = true;
      }

      while (dx[i] && graph[nblue.x + dx[i]][nblue.y] != '#') {
        nblue.x += dx[i];
        if (graph[nblue.x][blue.y] == 'O') blue_flag = true;
      }
      while (dy[i] && graph[nblue.x][nblue.y + dy[i]] != '#') {
        nblue.y += dy[i];
        if (graph[nblue.x][nblue.y] == 'O') blue_flag = true;
      }

      if (blue_flag)
        continue;
      else if (red_flag)
        return cnt + 1;

      if (nred == nblue) {
        if (dx[i] == -1) {
          if (red.x < blue.x)
            ++nblue.x;
          else
            ++nred.x;
        } else if (dx[i] == 1) {
          if (red.x < blue.x)
            --nred.x;
          else
            --nblue.x;
        } else if (dy[i] == -1) {
          if (red.y < blue.y)
            ++nblue.y;
          else
            ++nred.y;
        } else {
          if (red.y < blue.y)
            --nred.y;
          else
            --nblue.y;
        }
      }

      if (visited.find({nred, nblue}) == visited.end()) {
        q.push({nred, nblue, cnt + 1});
        visited.insert({nred, nblue});
      }
    }
  }

  return -1;
}

int main() {
  scanf("%d%d", &N, &M);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      scanf(" %c", &graph[i][j]);
      if (graph[i][j] == 'R')
        red = {i, j};
      else if (graph[i][j] == 'B')
        blue = {i, j};
    }
  }

  printf("%d", bfs(red, blue));
}