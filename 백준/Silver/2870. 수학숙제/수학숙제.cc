#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<string> v;

int main() {
  int N;
  cin >> N;
  while (N--) {
    string s, num;
    cin >> s;
    for (char c : s) {
      if (isdigit(c))
        num += c;
      else {
        if (num.size()) v.push_back(num);
        num.clear();
      }
    }
    if (num.size()) v.push_back(num);
  }
  for (auto &s : v) {
    int i = 0;
    while (s[i] == '0') i++;
    s = s.substr(i);
    if (!s.size()) s = "0";
  }
  sort(v.begin(), v.end(), [](auto &s, auto &t) {
    if (s.length() == t.length()) {
      for (int len = s.length(), i = 0; i < len; i++) {
        if (s[i] == t[i]) continue;
        return s[i] < t[i];
      }
    }
    return s.length() < t.length();
  });
  for (auto s : v) cout << s << '\n';
}