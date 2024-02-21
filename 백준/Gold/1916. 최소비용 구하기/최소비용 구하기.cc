#include <iostream>
#include <queue>

using namespace std;
using ll = long long;

const ll INF = 1'000'000'000;
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

  int N, M;
  int src, dest;

  cin >> N >> M;
  fill(dists + 1, dists + N + 1, INF);
  for (int dist, i = 0; i < M; i++) {
    cin >> src >> dest >> dist;
    graph[src].push_back({dest, dist});
  }
  cin >> src >> dest;
  dijkstra(src);
  cout << dists[dest];
}