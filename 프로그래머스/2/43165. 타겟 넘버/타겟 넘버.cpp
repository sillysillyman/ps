#include <queue>
#include <vector>

using namespace std;

int solution(vector<int> numbers, int target) {
  int answer = 0;
  queue<pair<int, int>> queue;

  queue.push({0, 0});
  while (!queue.empty()) {
    auto [num, next_idx] = queue.front();

    if (num == target && next_idx == numbers.size()) ++answer;
    queue.pop();
    if (next_idx < numbers.size()) {
      queue.push({num - numbers[next_idx], next_idx + 1});
      queue.push({num + numbers[next_idx], next_idx + 1});
    }
  }
  return answer;
}