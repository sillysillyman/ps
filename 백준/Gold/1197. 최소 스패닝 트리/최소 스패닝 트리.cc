#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Edge {
  int src, dest, weight;
};

const int MAX_V = 10'000;
int parents[MAX_V + 1];
vector<Edge> edges;
vector<pair<int, int>> graph[MAX_V + 1];

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

  int V, E;

  cin >> V >> E;
  for (int i = 1; i <= V; i++) parents[i] = i;
  for (int A, B, C, i = 0; i < E; i++) {
    Edge edge;

    cin >> A >> B >> C;
    edge  = {A, B, C};
    edges.push_back(edge);
  }
  sort(edges.begin(), edges.end(), [](Edge& u, Edge& v) {
    return u.weight < v.weight;
    }
  );

  int weight = 0;

  for (Edge edge : edges) {
    if (find(edge.src) != find(edge.dest)) {
      merge(edge.src, edge.dest);
      weight += edge.weight;
    }
  }
  cout << weight;
}