#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;

  cin >> T;
  while (T--) {
    int K, M, P;

    cin >> K >> M >> P;

    vector<int> indeg(M, 0);
    vector<pair<int, bool>> num(M, {0, false});
    vector<vector<int>> graph(M);

    while (P--) {
      int A, B;

      cin >> A >> B;
      --A;
      --B;
      ++indeg[B];
      graph[A].push_back(B);
    }

    queue<int> q;
    for (int i = 0; i < M; ++i) {
      if (!indeg[i]) {
        q.push(i);
        num[i].first = 1;
      }
    }
    while (!q.empty()) {
      int curr = q.front();

      q.pop();
      for (int next : graph[curr]) {
        if (!--indeg[next]) q.push(next);
        if (num[next].second) {
          num[next].first = max(num[next].first, num[curr].first);
        } else {
          if (num[next].first == num[curr].first) {
            num[next].first += 1;
            num[next].second = true;
          } else {
            num[next].first = max(num[next].first, num[curr].first);
          }
        }
      }
    }
    int max_num = 0;
    for (int i = 0; i < num.size(); i++) {
      max_num = max(max_num, num[i].first);
    }
    cout << K << ' ' << max_num << '\n';
  }
}