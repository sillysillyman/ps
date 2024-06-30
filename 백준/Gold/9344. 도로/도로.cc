#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

struct Edge {
  int from, to, cost;
};

const int MAX_N = 10'001;
int parents[MAX_N];

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
  int T;

  scanf("%d", &T);
  while (T--) {
    int N, M, p, q;
    vector<Edge> edges, tree;

    scanf("%d %d %d %d", &N, &M, &p, &q);
    for (int i = 1; i <= N; i++) parents[i] = i;
    while (M--) {
      int from, to, cost;

      scanf("%d %d %d", &from, &to, &cost);
      edges.push_back(Edge{from, to, cost});
    }
    sort(edges.begin(), edges.end(),
         [](const Edge& a, const Edge& b) { return a.cost < b.cost; });
    for (Edge& edge : edges) {
      auto& [from, to, cost] = edge;

      if (find(from) == find(to)) continue;
      tree.push_back(edge);
      merge(from, to);
    }

    bool buildable = false;

    for (Edge& edge : tree) {
      if ((edge.from == p && edge.to == q) ||
          (edge.from == q && edge.to == p)) {
        buildable = true;
        break;
      }
    }
    if (buildable)
      printf("YES\n");
    else
      printf("NO\n");
  }
}