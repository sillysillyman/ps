#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

struct Edge {
  int u, v;
  ll c;

  bool operator<(const Edge& other) const { return c < other.c; }
};

int n;
vector<int> p;
vector<Edge> edges;

int find(int x) { return x == p[x] ? x : p[x] = find(p[x]); }

void unite(int x, int y) { p[find(x)] = find(y); }

ll mst() {
  ll res = 0;

  sort(edges.begin(), edges.end());
  for (auto& [u, v, c] : edges) {
    if (find(u) == find(v)) continue;
    unite(u, v);
    res += c;
  }

  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;

  cin >> T;
  while (T--) {
    int m;

    cin >> n >> m;
    p.resize(n);
    edges.clear();
    for (int i = 1; i < n; i++) {
      int u;
      ll c;

      cin >> u >> c;
      edges.push_back({i, u, c});
    }

    ll res = 0;
    while (m--) {
      int u, v;
      ll c;

      for (int i = 0; i < n; i++) p[i] = i;
      cin >> u >> v >> c;
      edges.push_back({u, v, c});
      res ^= mst();
    }
    cout << res << '\n';
  }
}