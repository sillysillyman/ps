#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  while (true) {
    int n, dist = 0;
    pair<int, int> logs[13];

    cin >> n;
    if (n == -1) break;
    for (int i = 1; i <= n; i++) {
      cin >> logs[i].first >> logs[i].second;
      dist += logs[i].first * (logs[i].second - logs[i - 1].second);
    }
    cout << dist << " miles\n";
  }
}