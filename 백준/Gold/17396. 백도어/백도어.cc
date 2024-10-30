#include <iostream>
#include <queue>
#include <vector>

using namespace std;
using ll = long long;

const int MAX_N = 100'000;
const ll INF = 100'000'000'000;
bool wards[MAX_N];
ll times[MAX_N];
vector<pair<int, ll>> graph[MAX_N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, M;

  cin >> N >> M;
  fill(times, times + N, INF);
  for (int i = 0; i < N; i++) cin >> wards[i];
  while (M--) {
    int a, b, t;

    cin >> a >> b >> t;
    graph[a].push_back({b, t});
    graph[b].push_back({a, t});
  }

  priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;

  pq.push({0, 0});
  times[0] = 0;
  while (!pq.empty()) {
    auto [curr_time, curr] = pq.top();

    pq.pop();
    if (curr_time > times[curr]) continue;
    for (auto [next, time] : graph[curr]) {
      if (ll next_time = curr_time + time;
          (!wards[next] || next == N - 1) && next_time < times[next]) {
        times[next] = next_time;
        pq.push({next_time, next});
      }
    }
  }
  cout << (times[N - 1] == INF ? -1 : times[N - 1]);
}