#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Edge {
  int src, dest, weight;

  bool operator<(const Edge& other) const { return weight < other.weight; }
};

const int MAX_V = 10'000;
int parents[MAX_V];
vector<Edge> edges;

int find(int x) { return x == parents[x] ? x : parents[x] = find(parents[x]); }

void unite(int x, int y) { parents[find(x)] = find(y); }

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int V, E, weight = 0;

  cin >> V >> E;
  for (int i = 0; i < V; i++) parents[i] = i;
  while (E--) {
    int A, B, C;
    cin >> A >> B >> C;
    edges.push_back({A, B, C});
  }
  sort(edges.begin(), edges.end());
  for (Edge& edge : edges) {
    if (find(edge.src) != find(edge.dest)) {
      unite(edge.src, edge.dest);
      weight += edge.weight;
    }
  }
  cout << weight;
}