#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
  string answer(number.length() - k, ' ');
  vector<char> stack;

  for (char& digit : number) {
    while (!stack.empty() && stack.back() < digit && k > 0) {
      stack.pop_back();
      --k;
    }
    stack.push_back(digit);
  }
  while (k > 0) {
    stack.pop_back();
    --k;
  }
  for (int i = stack.size() - 1; i >= 0; i--) {
    answer[i] = stack.back();
    stack.pop_back();
  }
  return answer;
}