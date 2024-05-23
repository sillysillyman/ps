#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<int> order) {
  int answer = 0;
  vector<int> sequence;
  vector<int> stack;

  for (int i = order.size(); i > 0; i--) sequence.push_back(i);
  reverse(order.begin(), order.end());
  while (!sequence.empty()) {
    if (!sequence.empty() && sequence.back() == order.back()) {
      sequence.pop_back();
      order.pop_back();
      ++answer;
    } else if (!stack.empty() && stack.back() == order.back()) {
      stack.pop_back();
      order.pop_back();
      ++answer;
    } else {
      stack.push_back(sequence.back());
      sequence.pop_back();
    }
  }
  while (!order.empty() && !stack.empty() && order.back() == stack.back()) {
    order.pop_back();
    stack.pop_back();
    ++answer;
  }
  return answer;
}