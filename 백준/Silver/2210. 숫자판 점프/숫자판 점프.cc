#include <iostream>
#include <set>

using namespace std;

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
char graph[5][5];
set<int> nums;

bool is_inside(int x, int y) { return 0 <= x && x < 5 && 0 <= y && y < 5; }

void dfs(int x, int y, string num) {
  if (num.length() == 6) {
    nums.insert(stoi(num));
    return;
  }
  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];

    if (!is_inside(nx, ny)) continue;
    dfs(nx, ny, num + graph[nx][ny]);
  }
}

int main() {
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) cin >> graph[i][j];
  }
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) dfs(i, j, "");
  }
  cout << nums.size();
}