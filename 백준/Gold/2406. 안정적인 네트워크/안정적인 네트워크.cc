#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

struct Edge {
  int from, to, cost;
};

int p[1'000];
vector<Edge> edges;
vector<Edge> connected;

int find(int x) { return x == p[x] ? x : p[x] = find(p[x]); }

void unite(int x, int y) { p[find(x)] = find(y); }

int main() {
  int n, m;

  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) p[i] = i;
  while (m--) {
    int from, to;

    scanf("%d%d", &from, &to);
    --from, --to;
    unite(from, to);
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int cost;
      scanf("%d", &cost);
      if (i && i < j) edges.push_back({i, j, cost});
    }
  }

  int X = 0, K = 0;
  sort(edges.begin(), edges.end(),
       [](Edge& e1, Edge& e2) { return e1.cost < e2.cost; });
  for (Edge& edge : edges) {
    if (find(edge.from) != find(edge.to)) {
      unite(edge.from, edge.to);
      X += edge.cost;
      ++K;
      connected.push_back(edge);
    }
  }

  printf("%d %d\n", X, K);
  for (Edge& edge : connected) printf("%d %d\n", edge.from + 1, edge.to + 1);
}