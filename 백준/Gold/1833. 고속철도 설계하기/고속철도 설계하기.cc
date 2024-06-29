#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Edge {
  int from, to, cost;
};

int parents[201];
vector<Edge> edges;

int find(int x) {
  if (x == parents[x]) return x;
  return parents[x] = find(parents[x]);
}

void merge(int x, int y) {
  x = find(x);
  y = find(y);
  if (x == y) return;
  if (x < y)
    parents[y] = x;
  else
    parents[x] = y;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;

  cin >> N;
  for (int i = 1; i <= N; i++) parents[i] = i;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      int cost;

      cin >> cost;
      if (i >= j) continue;
      edges.push_back(Edge{i, j, cost});
    }
  }
  sort(edges.begin(), edges.end(),
       [](const Edge& a, const Edge& b) { return a.cost < b.cost; });

  int C = 0, M = 0;
  vector<Edge> new_edges;

  for (Edge& edge : edges) {
    auto& [from, to, cost] = edge;

    if (cost < 0)
      C += -cost;
    else if (find(from) != find(to)) {
      C += cost;
      ++M;
      new_edges.push_back(edge);
    }
    merge(from, to);
  }
  cout << C << ' ' << M << '\n';
  for (auto& edge : new_edges) cout << edge.from << ' ' << edge.to << '\n';
}