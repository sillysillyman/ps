#include <iostream>
#include <vector>

using namespace std;

struct Edge {
  int from, to, dist;
};

const int INF = 25'000'000;
int N;
int dists[501];
vector<Edge> edges;

bool bellman_ford() {
  for (int i = 1; i <= N; i++) {
    for (auto edge : edges) {
      auto [from, to, dist] = edge;

      if (dists[to] > dists[from] + dist) {
        dists[to] = dists[from] + dist;
        if (i == N) return true;
      }
    }
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int TC;

  cin >> TC;
  while (TC--) {
    int M, W;

    cin >> N >> M >> W;
    fill(dists + 1, dists + N + 1, INF);
    edges.clear();
    for (int S, E, T, i = 0; i < M; i++) {
      cin >> S >> E >> T;
      edges.push_back({S, E, T});
      edges.push_back({E, S, T});
    }
    for (int S, E, T, i = 0; i < W; i++) {
      cin >> S >> E >> T;
      edges.push_back({S, E, -T});
    }
    if (bellman_ford())
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}