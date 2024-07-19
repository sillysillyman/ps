#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;

  cin >> T;
  while (T--) {
    int time = 0, slen, plen;
    string str, pattern;

    cin >> str >> pattern;
    slen = str.length();
    plen = pattern.length();
    for (int i = 0; i < slen;) {
      if (i <= slen - plen && str.substr(i, plen) == pattern)
        i += plen;
      else
        ++i;
      ++time;
    }
    cout << time << '\n';
  }
}