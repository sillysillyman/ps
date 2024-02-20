#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int times[501];
int accumulated_times[501];
int indegrees[501];
vector<int> orders[501];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N;
  queue<int> q;

  cin >> N;
  for (int time, i = 1; i <= N; i++) {
    cin >> time;
    times[i] = time;
    accumulated_times[i] = time;
    while (true) {
      int prerequisite;

      cin >> prerequisite;
      if (prerequisite == -1) break;
      indegrees[i]++;
      orders[prerequisite].push_back(i);
    }
  }
  for (int i = 1; i <= N; i++) {
    if (indegrees[i] == 0) q.push(i);
  }
  for (int i = 1; i <= N; i++) {
    int prerequisite = q.front();

    q.pop();
    for (int dependency : orders[prerequisite]) {
      accumulated_times[dependency] =
          max(accumulated_times[dependency],
              accumulated_times[prerequisite] + times[dependency]);
      if (--indegrees[dependency] == 0) q.push(dependency);
    }
  }
  for (int i = 1; i <= N; i++) cout << accumulated_times[i] << '\n';
}