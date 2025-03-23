#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

bool is_square_number(long long n) { return pow((long long)sqrt(n), 2) == n; }

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  cin >> T;
  while (T--) {
    bool flag = true;
    string N;
    cin >> N;

    if (is_square_number(stoll(N))) {
      reverse(N.begin(), N.end());
      if (is_square_number(stoll(N))) {
        cout << "YES\n";
        flag = false;
      }
    }
    if (flag) cout << "NO\n";
  }
}