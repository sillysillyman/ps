#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  string S;

  cin >> S;
  S.erase(unique(S.begin(), S.end()), S.end());

  int zeros = 0;
  int ones = 0;

  for (auto c : S) {
    if (c == '0')
      zeros++;
    else if (c == '1')
      ones++;
  }
  if (zeros >= ones)
    cout << ones;
  else
    cout << zeros;
}