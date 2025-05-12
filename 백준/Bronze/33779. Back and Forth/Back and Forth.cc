#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  string s, t;
  cin >> s;
  t = s;
  reverse(t.begin(), t.end());
  cout << (s == t ? "beep" : "boop");
}