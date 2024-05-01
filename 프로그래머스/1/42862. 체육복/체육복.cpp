#include <algorithm>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
  int answer = 0;
  vector<pair<bool, bool>> students(n + 2);

  for (auto i = lost.begin(); i < lost.end();) {
    if (auto j = find(reserve.begin(), reserve.end(), *i); j != reserve.end()) {
      reserve.erase(j);
      i = lost.erase(i);
    } else
      i++;
  }
  students[0] = {false, false};
  students[n + 1] = {false, false};
  fill(students.begin() + 1, students.end() - 1, make_pair(true, false));
  for (int i : lost) students[i].first = false;
  for (int i : reserve) students[i].second = true;
  for (int i = 1; i <= n; i++) {
    if (students[i].first) continue;
    if (students[i - 1].second) {
      students[i - 1].second = false;
      students[i].first = true;
    } else if (students[i + 1].second) {
      students[i + 1].second = false;
      students[i].first = true;
    }
  }
  for (int i = 1; i <= n; i++) answer += students[i].first ? 1 : 0;
  return answer;
}