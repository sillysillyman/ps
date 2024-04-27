#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
using ll = long long;

const ll INF = 10'000'000'000;
int src, dest;
int from[1001];
ll costs[1001];
vector<int> path;
vector<pair<int, ll>> graph[1001];

void dijkstra(int src) {
  priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;

  from[src] = 0;
  costs[src] = 0;
  pq.push({costs[src], src});
  while (!pq.empty()) {
    auto [curr_cost, curr] = pq.top();

    pq.pop();
    if (curr_cost > costs[curr]) continue;
    for (auto& [next, next_cost] : graph[curr]) {
      if (costs[next] > costs[curr] + next_cost) {
        from[next] = curr;
        costs[next] = costs[curr] + next_cost;
        pq.push({costs[next], next});
      }
    }
  }
}

void get_reversed_path(int curr) {
  path.push_back(curr);
  if (curr == src) return;
  get_reversed_path(from[curr]);
}

int main() {
  int n, m;

  cin >> n >> m;
  fill(costs + 1, costs + n + 1, INF);
  for (int i = 0; i < m; i++) {
    ll cost;

    cin >> src >> dest >> cost;
    graph[src].push_back({dest, cost});
  }
  cin >> src >> dest;
  dijkstra(src);
  get_reversed_path(dest);
  reverse(path.begin(), path.end());
  cout << costs[dest] << '\n' << path.size() << '\n';
  for (int& node : path) cout << node << ' ';
}