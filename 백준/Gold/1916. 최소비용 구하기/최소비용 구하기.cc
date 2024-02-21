#include <iostream>
#include <queue>

using namespace std;
using ll = long long;

const ll INF = 1'000'000'000;
int N, M;
ll dists[1001];
vector<pair<int, ll>> graph[1001];

void dijkstra(int src) {
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

  dists[src] = 0;
  pq.push({dists[src], src});
  while (!pq.empty()) {
    auto [curr_dist, curr] = pq.top();

    pq.pop();
    if (curr_dist > dists[curr]) continue;
    for (auto [next, next_dist] : graph[curr]) {
      if (dists[next] > dists[curr] + next_dist) {
        dists[next] = dists[curr] + next_dist;
        pq.push({next_dist, next});
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int src, dst;

  cin >> N >> M;
  fill(dists + 1, dists + N + 1, INF);
  for (int cost, i = 0; i < M; i++) {
    cin >> src >> dst >> cost;
    graph[src].push_back({dst, cost});
  }
  cin >> src >> dst;
  dijkstra(src);
  // for (int k = 1; k <= N; k++) {
  //   for (int i = 1; i <= N; i++) {
  //     for (int j = 1; j <= N; j++) {
  //       costs[i][j] = min(costs[i][j], costs[i][k] + costs[k][j]);
  //     }
  //   }
  // }
  cout << dists[dst];
}