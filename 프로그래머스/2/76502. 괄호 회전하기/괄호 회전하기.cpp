#include <string>
#include <vector>

using namespace std;

bool has_right_parenthes_pair(string s) {
  vector<char> stack;

  for (char& ch : s) {
    if (ch == '(' || ch == '{' || ch == '[')
      stack.push_back(ch);
    else {
      if (stack.empty()) return false;
      if (ch == ')' && stack.back() == '(')
        stack.pop_back();
      else if (ch == '}' && stack.back() == '{')
        stack.pop_back();
      else if (ch == ']' && stack.back() == '[')
        stack.pop_back();
      else
        return false;
    }
  }
  return stack.empty();
}

int solution(string s) {
  int answer = 0;

  for (int i = 1; i <= s.size(); i++) {
    if (has_right_parenthes_pair(s.substr(i, s.size() - i) + s.substr(0, i)))
      ++answer;
  }
  return answer;
}