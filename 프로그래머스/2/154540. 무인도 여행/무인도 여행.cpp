#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int R, C;
int area;
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
vector<vector<bool>> visited;
vector<vector<int>> graph;

void init(int row, int col, vector<string>& maps) {
  visited.assign(row, vector<bool>(col, false));
  graph.assign(row, vector<int>(col));
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++)
      graph[i][j] = maps[i][j] == 'X' ? 0 : maps[i][j] - '0';
  }
}

bool is_inside(int x, int y) { return 0 <= x && x < R && 0 <= y && y < C; }

void dfs(int x, int y) {
  visited[x][y] = true;
  area += graph[x][y];
  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];

    if (is_inside(nx, ny) && graph[nx][ny] && !visited[nx][ny]) dfs(nx, ny);
  }
}

vector<int> solution(vector<string> maps) {
  vector<int> answer;

  R = maps.size();
  C = maps[0].size();
  init(R, C, maps);
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      if (!visited[i][j] && graph[i][j]) {
        area = 0;
        dfs(i, j);
        if (area) answer.push_back(area);
      }
    }
  }
  if (answer.empty()) answer.push_back(-1);
  sort(answer.begin(), answer.end());
  return answer;
}