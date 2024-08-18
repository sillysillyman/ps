#include <iostream>

using namespace std;

int n, cnt;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  while (cin >> n) cnt += n > 0;
  cout << cnt;
}