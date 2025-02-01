#include <cstdio>
#include <queue>
#include <tuple>

using namespace std;

struct Pos {
  int x, y;

  bool operator==(const Pos& other) const {
    return x == other.x && y == other.y;
  }
};

int N, M;
Pos A, B;
int dx[9] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
int dy[9] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};
bool graph[20][20];
bool visited[20][20][20][20];

bool is_inside(Pos p) { return 0 <= p.x && p.x < N && 0 <= p.y && p.y < M; }

int bfs(Pos a, Pos b) {
  queue<tuple<Pos, Pos, int>> q;
  q.push(make_tuple(a, b, 0));
  visited[a.x][a.y][b.x][b.y] = true;

  while (!q.empty()) {
    auto [curr_a, curr_b, cnt] = q.front();
    q.pop();

    if (curr_a == B && curr_b == A) return cnt;

    for (int i = 0; i < 9; i++) {
      Pos next_a = {curr_a.x + dx[i], curr_a.y + dy[i]};

      if (is_inside(next_a) && graph[next_a.x][next_a.y]) {
        for (int j = 0; j < 9; j++) {
          if (i == 4 && j == 4) continue;

          Pos next_b = {curr_b.x + dx[j], curr_b.y + dy[j]};

          if (is_inside(next_b) && graph[next_b.x][next_b.y] &&
              !visited[next_a.x][next_a.y][next_b.x][next_b.y] &&
              !(next_a == next_b) && !(next_b == curr_a && next_a == curr_b)) {
            q.push(make_tuple(next_a, next_b, cnt + 1));
            visited[next_a.x][next_a.y][next_b.x][next_b.y] = true;
          }
        }
      }
    }
  }

  return -1;
}

int main() {
  scanf("%d %d", &N, &M);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      char c;
      scanf(" %c", &c);

      graph[i][j] = true;
      if (c == 'A')
        A = {i, j};
      else if (c == 'B')
        B = {i, j};
      else if (c == 'X')
        graph[i][j] = false;
    }
  }

  printf("%d", bfs(A, B));
}