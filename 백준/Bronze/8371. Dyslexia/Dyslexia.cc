#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, cnt = 0;
  string original, rewritten;

  cin >> n;
  cin >> original >> rewritten;
  for (int i = 0; i < n; i++) {
    if (original[i] != rewritten[i]) cnt++;
  }
  cout << cnt;
}