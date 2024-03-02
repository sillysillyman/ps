#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Edge {
  int idx, p, q, dist;
};

int parents[200000];
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
  cin.tie(NULL);
  while (true) {
    int m, n;
    int total_dist = 0;
    int min_dist = 0;

    cin >> m >> n;
    if (m == 0 && n == 0) break;
    edges.clear();
    fill(parents, parents + m, 0);
    for (int x, y, z, i = 0; i < n; i++) {
      cin >> x >> y >> z;
      total_dist += z;
      parents[i] = i;
      edges.push_back({i, x, y, z});
    }
    sort(edges.begin(), edges.end(),
         [](const Edge& u, const Edge& v) { return u.dist < v.dist; });
    for (auto edge : edges) {
      if (find(edge.p) == find(edge.q)) continue;
      merge(edge.p, edge.q);
      min_dist += edge.dist;
    }
    cout << total_dist - min_dist << '\n';
  }
}