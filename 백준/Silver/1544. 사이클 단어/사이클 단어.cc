#include <iostream>
#include <set>

using namespace std;

set<string> s;

int main() {
  int N;
  cin >> N;

  while (N--) {
    string str;
    cin >> str;

    bool flag = true;
    for (int len = str.length(), i = 0; i < len; i++) {
      if (s.find(str.substr(i, len - i) + str.substr(0, i)) != s.end()) {
        flag = false;
        break;
      }
    }
    if (flag) s.insert(str);
  }

  cout << s.size();
}