#include <iostream>

using namespace std;
using ll = long long;

const ll INF = 1'600'000'000;
ll graph[401][401];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int V, E;

  cin >> V >> E;
  fill(&graph[1][1], &graph[V][V + 1], INF);
  for (int from, to, i = 0; i < E; i++) {
    ll dist;

    cin >> from >> to >> dist;
    graph[from][to] = dist;
  }
  for (int i = 1; i <= V; i++) graph[i][i] = 0;
  for (int via = 1; via <= V; via++) {
    for (int from = 1; from <= V; from++) {
      for (int to = 1; to <= V; to++)
        graph[from][to] =
            min(graph[from][to], graph[from][via] + graph[via][to]);
    }
  }

  ll min_cycle_dist = INF;

  for (int i = 1; i <= V; i++) {
    for (int j = 1; j <= V; j++) {
      if (i == j) continue;
      min_cycle_dist = min(min_cycle_dist, graph[i][j] + graph[j][i]);
    }
  }
  if (min_cycle_dist == INF)
    cout << -1;
  else
    cout << min_cycle_dist;
}