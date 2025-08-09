#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  string s[3];
  cin >> s[0] >> s[1] >> s[2];
  sort(s, s + 3);
  cout << (s[0][0] == 'k' && s[1][0] == 'l' && s[2][0] == 'p' ? "GLOBAL" : "PONIX");
}