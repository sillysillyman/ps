#include <iostream>
#include <stack>

using namespace std;

int main() {
  string infix_expr;
  stack<char> s;

  cin >> infix_expr;
  for (char ch : infix_expr) {
    if (isalpha(ch))
      cout << ch;
    else if (ch == '(')
      s.push(ch);
    else if (ch == ')') {
      while (!s.empty() && s.top() != '(') {
        cout << s.top();
        s.pop();
      }
      s.pop();
    } else {
      while (!s.empty() && ((s.top() == '*' || s.top() == '/') ||
                            ((s.top() == '+' || s.top() == '-') &&
                             (ch == '+' || ch == '-')))) {
        cout << s.top();
        s.pop();
      }
      s.push(ch);
    }
  }
  while (!s.empty()) {
    cout << s.top();
    s.pop();
  }
}