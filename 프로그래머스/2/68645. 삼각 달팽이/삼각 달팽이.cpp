#include <vector>

using namespace std;

bool is_inside(int x, int y, int n) {
  return 0 <= x && x < n && 0 <= y && y <= x;
}

vector<int> solution(int n) {
  int val = 1;
  vector<int> answer;
  vector<vector<int>> triangle(n, vector<int>(n, 0));

  int x = 0, y = 0;

  while (is_inside(x, y, n) && !triangle[x][y]) {
    for (; x < n; x++) {
      if (triangle[x][y]) break;
      triangle[x][y] = val++;
    }
    --x;
    ++y;
    for (; y < n; y++) {
      if (triangle[x][y]) break;
      triangle[x][y] = val++;
    }
    --y;
    for (int k = 1; k <= n; k++) {
      if (triangle[x - k][y - k]) {
        x -= k - 1;
        y -= k - 1;
        break;
      }
      triangle[x - k][y - k] = val++;
    }
    ++x;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i + 1; j++) answer.push_back(triangle[i][j]);
  }
  return answer;
}