#include <string>
#include <vector>

using namespace std;

bool has_matching_parentheses(string s) {
  vector<char> stack;

  for (char& ch : s) {
    if (ch == '(' || ch == '{' || ch == '[')
      stack.push_back(ch);
    else {
      if (stack.empty()) return false;

      int top = stack.back();

      if (ch == ')' && top == '(')
        stack.pop_back();
      else if (ch == '}' && top == '{')
        stack.pop_back();
      else if (ch == ']' && top == '[')
        stack.pop_back();
      else
        return false;
    }
  }
  return stack.empty();
}

int solution(string s) {
  int answer = 0;
  int len = s.length();

  for (int i = 0; i < len; i++) {
    if (has_matching_parentheses(s.substr(i) + s.substr(0, i))) ++answer;
  }
  return answer;
}