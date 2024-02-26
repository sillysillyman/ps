#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int INF = 200'000'000;
int dists[800];
vector<pair<int, int>> graph[801];

void dijkstra(int src) {
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

  dists[src] = 0;
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

  int N, E;

  cin >> N >> E;
  for (int a, b, c, i = 0; i < E; i++) {
    cin >> a >> b >> c;
    graph[a].push_back({b, c});
    graph[b].push_back({a, c});
  }

  int v1, v2;
  int dist_from_v1 = 0, dist_from_v2 = 0;

  cin >> v1 >> v2;
  fill(dists + 1, dists + N + 1, INF);
  dijkstra(v1);
  dist_from_v1 += dists[1];
  dist_from_v1 += dists[v2];
  dist_from_v2 += dists[N];
  fill(dists + 1, dists + N + 1, INF);
  dijkstra(v2);
  dist_from_v1 += dists[N];
  dist_from_v2 += dists[1];
  dist_from_v2 += dists[v1];
  if (int min_dist = min(dist_from_v1, dist_from_v2); min_dist >= INF)
    cout << -1;
  else
    cout << min_dist;
}