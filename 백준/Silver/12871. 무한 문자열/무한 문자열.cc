#include <iostream>
#include <numeric>

using namespace std;

int main() {
  string s, t;

  cin >> s >> t;
  int n = lcm(s.length(), t.length());
  string original_s = s, original_t = t;
  while (s.length() < n) s += original_s;
  while (t.length() < n) t += original_t;
  cout << (s == t);
}