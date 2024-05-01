#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
  int answer = 0;
  vector<bool> wall(n, true);

  for (int i = 0; i < section.size(); i++) wall[section[i] - 1] = false;
  for (int i = 0; i < n;) {
    if (wall[i] == false) {
      for (int j = 0; j < m && i + j < n; j++) wall[i + j] = true;
      answer++;
      i += m;
    } else
      i++;
  }
  return answer;
}