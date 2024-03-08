#include <iostream>
#include <stack>

using namespace std;

int main() {
  string parentheses;
  stack<char> s;

  cin >> parentheses;

  int num = 1;
  int value = 0;

  for (int i = 0; i < parentheses.length(); i++) {
    if (parentheses[i] == '(') {
      num *= 2;
      s.push('(');
    } else if (parentheses[i] == ')') {
      if (s.empty() || s.top() != '(') {
        cout << 0;
        return 0;
      }
      if (parentheses[i - 1] == '(') {
        value += num;
        num /= 2;
        s.pop();
      } else {
        num /= 2;
        s.pop();
      }
    } else if (parentheses[i] == '[') {
      num *= 3;
      s.push('[');
    } else if (parentheses[i] == ']') {
      if (s.empty() || s.top() != '[') {
        cout << 0;
        return 0;
      }
      if (parentheses[i - 1] == '[') {
        value += num;
        num /= 3;
        s.pop();
      } else {
        num /= 3;
        s.pop();
      }
    }
  }
  if (s.empty()) cout << value;
  else cout << 0;
}