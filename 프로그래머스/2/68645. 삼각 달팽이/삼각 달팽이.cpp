#include <vector>

using namespace std;

vector<int> solution(int n) {
  int val = 1, x = -1, y = 0;
  vector<int> answer;
  vector<vector<int>> triangle(n, vector<int>(n, 0));

  for (int step = 0; step < n; step++) {
    for (int i = step; i < n; i++) {
      if (step % 3 == 0)
        ++x;
      else if (step % 3 == 1)
        ++y;
      else {
        --x;
        --y;
      }
      triangle[x][y] = val++;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i; j++) answer.push_back(triangle[i][j]);
  }
  return answer;
}