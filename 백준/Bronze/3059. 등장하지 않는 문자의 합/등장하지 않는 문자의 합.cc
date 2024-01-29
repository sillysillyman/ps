#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  int T;

  cin >> T;
  while (T--) {
    int sum = 0;
    string S;

    cin >> S;
    sort(S.begin(), S.end());
    S.erase(unique(S.begin(), S.end()), S.end());
    for (char c = 'A'; c <= 'Z'; c++) sum += c;
    for (char c : S) sum -= c;
    cout << sum << '\n';
  }
}