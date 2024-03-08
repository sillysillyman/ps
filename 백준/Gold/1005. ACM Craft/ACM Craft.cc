#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int MAX_N = 1'000;
int indegrees[MAX_N + 1];
pair<int, int> times[MAX_N + 1];
vector<int> orders[MAX_N + 1];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int T;

  cin >> T;
  while (T--) {
    int N, K, W;
    queue<int> q;

    cin >> N >> K;
    fill(indegrees + 1, indegrees + N + 1, 0);
    for (int i = 1; i <= N; i++) orders[i].clear();
    for (int i = 1; i <= N; i++) {
      cin >> times[i].first;
      times[i].second = 0;
    }
    for (int X, Y, i = 0; i < K; i++) {
      cin >> X >> Y;
      orders[X].push_back(Y);
      indegrees[Y]++;
    }
    cin >> W;
    for (int i = 1; i <= N; i++) {
      if (!indegrees[i]) q.push(i);
    }
    while (!q.empty()) {
      int prev = q.front();

      q.pop();
      for (int next : orders[prev]) {
        if (--indegrees[next] == 0) q.push(next);
        times[next].second =
            max(times[next].second, times[prev].first + times[prev].second);
      }
    }
    cout << times[W].first + times[W].second << '\n';
  }
}