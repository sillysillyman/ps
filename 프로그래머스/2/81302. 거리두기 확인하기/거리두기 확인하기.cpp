#include <queue>
#include <string>
#include <vector>

using namespace std;

struct Pos {
  int x, y;
};

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
bool visited[5][5];
char graph[5][5];

bool is_inside(int x, int y) { return 0 <= x && x < 5 && 0 <= y && y < 5; }

bool bfs(Pos src) {
  queue<pair<Pos, int>> queue;

  queue.push({src, 0});
  visited[src.x][src.y] = true;
  while (!queue.empty()) {
    auto [curr, dist] = queue.front();

    queue.pop();
    if (dist == 2) continue;
    for (int i = 0; i < 4; i++) {
      int nx = curr.x + dx[i];
      int ny = curr.y + dy[i];

      if (is_inside(nx, ny) && !visited[nx][ny] && graph[nx][ny] != 'X') {
        if (graph[nx][ny] == 'P') return false;
        queue.push({{nx, ny}, dist + 1});
        visited[nx][ny] = true;
      }
    }
  }
  return true;
}

vector<int> solution(vector<vector<string>> places) {
  vector<int> answer;

  for (auto& place : places) {
    vector<Pos> people;

    fill(&visited[0][0], &visited[4][5], false);
    for (int i = 0; i < 5; i++) {
      for (int j = 0; j < 5; j++) {
        if (place[i][j] == 'P') people.push_back({i, j});
        graph[i][j] = place[i][j];
      }
    }

    bool is_valid = true;

    for (Pos person : people) {
      if (bfs(person)) continue;
      is_valid = false;
      answer.push_back(0);
      break;
    }
    if (is_valid) answer.push_back(1);
  }
  return answer;
}