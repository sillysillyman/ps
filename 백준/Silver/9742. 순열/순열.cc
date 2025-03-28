#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  string s;
  while (cin >> s >> n) {
    bool flag = false;
    cout << s << ' ' << n << " = ";

    if (n == 1)
      flag = true;
    else {
      for (int i = 2; i <= n; i++) {
        if (!next_permutation(s.begin(), s.end())) break;
        if (i == n) {
          flag = true;
          break;
        }
      }
    }
    cout << (flag ? s : "No permutation") << '\n';
  }
}