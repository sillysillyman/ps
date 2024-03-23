#include <iostream>
#include <list>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int T;

  cin >> T;
  while (T--) {
    string keylogger;
    list<char> pwd;
    auto cursor = pwd.begin();

    cin >> keylogger;
    for (char log : keylogger) {
      if (log == '<') {
        if (cursor != pwd.begin()) cursor--;
      } else if (log == '>') {
        if (cursor != pwd.end()) cursor++;
      } else if (log == '-') {
        if (!pwd.empty() && cursor != pwd.begin()) cursor = pwd.erase(--cursor);
      } else
        pwd.insert(cursor, log);
    }
    for (auto letter : pwd) cout << letter;
    cout << '\n';
  }
}