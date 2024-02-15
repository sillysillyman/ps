#include <iostream>
#include <stack>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N;
  string command;
  stack<int> s;

  cin >> N;
  while (N--) {
    cin >> command;
    if (command == "push") {
      int X;

      cin >> X;
      s.push(X);
    } else if (command == "pop") {
      if (s.empty())
        cout << -1 << '\n';
      else {
        cout << s.top() << '\n';
        s.pop();
      }
    } else if (command == "size")
      cout << s.size() << '\n';
    else if (command == "empty") {
      cout << s.empty() << '\n';
    } else if (command == "top") {
      cout << (s.empty() ? -1 : s.top()) << '\n';
    }
  }
}