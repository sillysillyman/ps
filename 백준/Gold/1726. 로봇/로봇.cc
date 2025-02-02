#include <cstdio>
#include <queue>

using namespace std;

struct Pos {
  int x, y, dir;

  bool operator==(const Pos& other) const {
    return x == other.x && y == other.y && dir == other.dir;
  }
};

int M, N;
int graph[100][100];
bool visited[100][100][5];

bool is_inside(Pos p) { return 0 <= p.x && p.x < M && 0 <= p.y && p.y < N; }

int bfs(Pos src, Pos dest) {
  queue<pair<Pos, int>> q;
  q.push({src, 0});
  visited[src.x][src.y][src.dir] = true;

  while (!q.empty()) {
    auto [curr, cnt] = q.front();

    q.pop();

    // printf("cnt = %d\n", cnt);
    // for (int i = 0; i < M; i++) {
    //   for (int j = 0; j < N; j++) {
    //     if (i == curr.x && j == curr.y) {
    //       if (curr.dir == 1)
    //         printf("> ");
    //       else if (curr.dir == 2)
    //         printf("< ");
    //       else if (curr.dir == 3)
    //         printf("v ");
    //       else
    //         printf("^ ");
    //     } else
    //       printf("%d ", graph[i][j]);
    //   }
    //   printf("\n");
    // }
    // printf("\n");

    if (curr == dest) return cnt;

    if (curr.dir == 1 || curr.dir == 2) {
      if (!visited[curr.x][curr.y][3]) {
        visited[curr.x][curr.y][3] = true;
        q.push({{curr.x, curr.y, 3}, cnt + 1});
      }
      if (!visited[curr.x][curr.y][4]) {
        visited[curr.x][curr.y][4] = true;
        q.push({{curr.x, curr.y, 4}, cnt + 1});
      }
    } else if (curr.dir == 3 || curr.dir == 4) {
      if (!visited[curr.x][curr.y][1]) {
        visited[curr.x][curr.y][1] = true;
        q.push({{curr.x, curr.y, 1}, cnt + 1});
      }
      if (!visited[curr.x][curr.y][2]) {
        visited[curr.x][curr.y][2] = true;
        q.push({{curr.x, curr.y, 2}, cnt + 1});
      }
    }
    for (int k = 1; k <= 3; k++) {
      //   int nx = curr.x + k * (curr.dir == 3 ? 1 : curr.dir == 4 ? -1 : 0);
      //   int ny = curr.y + k * (curr.dir == 1 ? 1 : curr.dir == 2 ? -1 : 0);
      Pos next = {curr.x + k * (curr.dir == 3   ? 1
                                : curr.dir == 4 ? -1
                                                : 0),
                  curr.y + k * (curr.dir == 1   ? 1
                                : curr.dir == 2 ? -1
                                                : 0),
                  curr.dir};

      bool flag = true;
      for (int i = 1; i <= k; i++) {
        Pos check = {curr.x + i * (curr.dir == 3   ? 1
                                   : curr.dir == 4 ? -1
                                                   : 0),
                     curr.y + i * (curr.dir == 1   ? 1
                                   : curr.dir == 2 ? -1
                                                   : 0),
                     curr.dir};
        if (!is_inside(check) || graph[check.x][check.y]) {
          flag = false;
          break;
        }
      }

      if (flag && !visited[next.x][next.y][curr.dir]) {
        visited[next.x][next.y][curr.dir] = true;
        q.push({next, cnt + 1});
      }
    }
  }

  return -1;
}

int main() {
  scanf("%d%d", &M, &N);
  for (int i = 0; i < M; i++)
    for (int j = 0; j < N; j++) scanf("%d", &graph[i][j]);

  Pos src, dest;
  scanf("%d%d%d%d%d%d", &src.x, &src.y, &src.dir, &dest.x, &dest.y, &dest.dir);
  --src.x, --src.y, --dest.x, --dest.y;

  printf("%d", bfs(src, dest));
}