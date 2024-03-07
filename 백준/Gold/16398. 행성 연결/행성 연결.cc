#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

struct Edge {
  int from, to;
  ll cost;
};

int parents[1000];
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

  int N;

  cin >> N;
  for (int i = 0; i < N; i++) parents[i] = i;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      ll cost;

      cin >> cost;
      if (i < j) edges.push_back({i, j, cost});
    }
  }
  sort(edges.begin(), edges.end(),
       [](Edge& u, Edge& v) { return u.cost < v.cost; });

  long long total_cost = 0;

  for (auto& edge : edges) {
    if (find(edge.from) == find(edge.to)) continue;
    merge(find(edge.from), find(edge.to));
    total_cost += edge.cost;
  }
  cout << total_cost;
}