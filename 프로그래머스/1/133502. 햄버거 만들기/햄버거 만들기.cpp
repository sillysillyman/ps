#include <vector>

using namespace std;

int solution(vector<int> ingredient) {
  int answer = 0;
  vector<int> stack;

  for (int i : ingredient) {
    stack.push_back(i);
    if (stack.size() >= 4 &&
        vector<int>(stack.end() - 4, stack.end()) == vector<int>{1, 2, 3, 1}) {
      stack.erase(stack.end() - 4, stack.end());
      answer++;
    }
  }
  return answer;
}