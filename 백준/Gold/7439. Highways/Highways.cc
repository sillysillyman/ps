#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Node {
  int idx, x, y;
};

struct Edge {
  int from, to, dist;
};

const int MAX_N = 751;
int parents[MAX_N];
vector<Node> nodes;
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

int distance_squared(Node& a, Node& b) {
  return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, M;
  vector<pair<int, int>> connected;

  cin >> N;
  for (int i = 1; i <= N; i++) parents[i] = i;
  for (int i = 1; i <= N; i++) {
    int x, y;

    cin >> x >> y;
    nodes.push_back(Node{i, x, y});
  }
  cin >> M;
  while (M--) {
    int node1, node2;

    cin >> node1 >> node2;
    merge(node1, node2);
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < i; j++)
      edges.push_back(Edge{nodes[i].idx, nodes[j].idx,
                           distance_squared(nodes[i], nodes[j])});
  }
  sort(edges.begin(), edges.end(),
       [](const Edge& a, const Edge& b) { return a.dist < b.dist; });
  for (Edge& edge : edges) {
    auto& [from, to, dist] = edge;

    if (find(from) == find(to)) continue;
    connected.push_back({from, to});
    merge(from, to);
  }
  for (auto& [from, to] : connected) cout << from << ' ' << to << '\n';
}