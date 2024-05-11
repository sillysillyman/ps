#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int solution(vector<int> priorities, int location) {
  int answer = 0;
  queue<pair<int, int>> queue;

  for (int i = 0; i < priorities.size(); i++) queue.push({priorities[i], i});
  sort(priorities.begin(), priorities.end());
  while (!queue.empty()) {
    auto [priority, idx] = queue.front();

    if (priority == priorities.back()) {
      queue.pop();
      priorities.pop_back();
      ++answer;
      if (idx == location) break;
    } else {
      queue.pop();
      queue.push({priority, idx});
    }
  }
  return answer;
}