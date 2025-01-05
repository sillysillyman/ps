#include <iostream>

using namespace std;

string s, t;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  while (cin >> s >> t) {
    int j = 0;
    for (int i = 0; i < t.size(); i++)
      if (s[j] == t[i]) ++j;
    cout << (j == s.length() ? "Yes" : "No") << '\n';
  }
}