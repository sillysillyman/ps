#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, prefix = 0;
  long long s = 0;
  cin >> n;
  for (int x, i = 0; i < n; i++) {
    cin >> x;
    s += prefix * x;
    prefix += x;
  }
  cout << s;
}