#include <iostream>
#include <queue>
#include <vector>

using namespace std;
using ll = long long;

const ll INF = 10'000'000'000;
int src, dest;
int from[1001];
ll costs[1001];
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

  vector<int> reversed_path;

  for (int i = dest; i != 0; i = from[i]) reversed_path.push_back(i);
  cout << costs[dest] << '\n' << reversed_path.size() << '\n';
  for (auto node = reversed_path.rbegin(); node != reversed_path.rend(); node++)
    cout << *node << ' ';
}