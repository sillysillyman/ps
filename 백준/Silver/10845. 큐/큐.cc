#include <iostream>
#include <queue>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N;
  string command;
  queue<int> q;

  cin >> N;
  while (N--) {
    cin >> command;
    if (command == "push") {
      int X;

      cin >> X;
      q.push(X);
    } else if (command == "pop") {
      if (q.empty())
        cout << -1 << '\n';
      else {
        cout << q.front() << '\n';
        q.pop();
      }
    } else if (command == "size")
      cout << q.size() << '\n';
    else if (command == "empty")
      cout << q.empty() << '\n';
    else if (command == "front")
      cout << (q.empty() ? -1 : q.front()) << '\n';
    else if (command == "back")
      cout << (q.empty() ? -1 : q.back()) << '\n';
  }
}