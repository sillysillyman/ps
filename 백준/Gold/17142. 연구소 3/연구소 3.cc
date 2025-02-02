#include <algorithm>
#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

struct Pos {
  int x, y;
};

const int MAX_TIME = 2'500;
int N, M;
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
vector<int> flag;
vector<Pos> viruses;
int graph[50][50];
int visited[50][50];

bool is_inside(Pos p) { return 0 <= p.x && p.x < N && 0 <= p.y && p.y < N; }

int bfs() {
  fill(&visited[0][0], &visited[N - 1][N], MAX_TIME);

  queue<pair<Pos, int>> q;
  for (int i = 0; i < viruses.size(); i++) {
    if (flag[i]) {
      q.push({viruses[i], 0});
      visited[viruses[i].x][viruses[i].y] = 0;
    }
  }

  while (!q.empty()) {
    auto [curr, t] = q.front();

    q.pop();
    for (int i = 0; i < 4; i++) {
      Pos next = {curr.x + dx[i], curr.y + dy[i]};

      if (is_inside(next) && t + 1 < visited[next.x][next.y] &&
          graph[next.x][next.y] != 1) {
        q.push({next, t + 1});
        visited[next.x][next.y] = t + 1;
      }
    }
  }

  int time = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (visited[i][j] == MAX_TIME && !graph[i][j]) return MAX_TIME;
      if (!graph[i][j]) time = max(time, visited[i][j]);
    }
  }

  return time;
}

int main() {
  scanf("%d%d", &N, &M);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      scanf("%d", &graph[i][j]);
      if (graph[i][j] == 2) {
        viruses.push_back({i, j});
        flag.push_back(0);
      }
    }
  }

  fill(flag.end() - M, flag.end(), 1);

  int min_time = MAX_TIME;
  do min_time = min(min_time, bfs());
  while (next_permutation(flag.begin(), flag.end()));

  printf("%d", min_time == MAX_TIME ? -1 : min_time);
}