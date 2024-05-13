#include <algorithm>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers) {
  vector<int> stack;
  vector<int> answer(numbers.size(), -1);

  for (int i = numbers.size() - 1; i >= 0; i--) {
    while (!stack.empty() && numbers[i] >= stack.back()) stack.pop_back();
    if (stack.empty())
      answer[i] = -1;
    else
      answer[i] = stack.back();
    stack.push_back(numbers[i]);
  }
  return answer;
}