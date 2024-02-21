#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int MAX_V = 20'000;
const int INF = 200'001;
int dists[MAX_V + 1];
vector<pair<int, int>> graph[MAX_V + 1];

void dijkstra(int src) {
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

  pq.push({dists[src], src});
  while (!pq.empty()) {
    auto [curr_dist, curr] = pq.top();

    pq.pop();
    for (auto [next, next_dist] : graph[curr]) {
      if (dists[next] > dists[curr] + next_dist) {
        dists[next] = dists[curr] + next_dist;
        pq.push({dists[next], next});
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int V, E, K;

  cin >> V >> E >> K;
  for (int u, v, w, i = 0; i < E; i++) {
    cin >> u >> v >> w;
    graph[u].push_back({v, w});
  }
  for (int i = 1; i <= V; i++) dists[i] = INF;
  dists[K] = 0;
  dijkstra(K);
  for (int i = 1; i <= V; i++) {
    if (dists[i] >= INF) cout << "INF\n";
    else cout << dists[i] << '\n';
  }
}