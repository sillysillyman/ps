#include <iostream>
#include <stack>

using namespace std;

int main() {
  int t = 1;
  string str;

  while (true) {
    cin >> str;
    if (str[0] == '-') break;

    stack<char> open, closed;

    for (auto brace : str) {
      if (brace == '{')
        open.push(brace);
      else {
        if (open.empty())
          closed.push(brace);
        else
          open.pop();
      }
    }
    if (open.size() % 2 && closed.size() % 2)
      cout << t << ". " << (open.size() + 1) / 2 + (closed.size() + 1) / 2
           << '\n';
    else
      cout << t << ". " << (open.size() + closed.size()) / 2 << '\n';
    t++;
  }
}