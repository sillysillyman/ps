#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Edge {
  int from, to, cost;
};

int p[1'000];
vector<Edge> edges;
vector<pair<int, int>> connected;

int find(int x) { return x == p[x] ? x : p[x] = find(p[x]); }

void unite(int x, int y) { p[find(x)] = find(y); }

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;

  cin >> n >> m;
  for (int i = 0; i < n; i++) p[i] = i;
  while (m--) {
    int from, to;

    cin >> from >> to;
    --from, --to;
    unite(from, to);
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int cost;
      cin >> cost;
      if (i && i < j) edges.push_back({i, j, cost});
    }
  }

  int X = 0, K = 0;
  sort(edges.begin(), edges.end(),
       [](Edge& e1, Edge& e2) { return e1.cost < e2.cost; });
  for (Edge& edge : edges) {
    int from = edge.from, to = edge.to;

    if (find(from) != find(to)) {
      unite(from, to);
      X += edge.cost;
      ++K;
      connected.push_back({from, to});
    }
  }

  cout << X << ' ' << K << '\n';
  for (auto& [from, to] : connected) cout << from + 1 << ' ' << to + 1 << '\n';
}