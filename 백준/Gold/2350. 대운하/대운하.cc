#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Edge {
  int from, to, width;
};

const int MAX_N = 1'001;
int parents[MAX_N];
vector<Edge> edges;
vector<pair<int, int>> tree[MAX_N];

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

int dfs(int prev, int curr, int dest, int min_width) {
  if (curr == dest) return min_width;
  for (auto& [next, width] : tree[curr]) {
    if (next == prev) continue;
    if (int result = dfs(curr, next, dest, min(min_width, width)); result != -1)
      return result;
  }
  return -1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, M, K;

  cin >> N >> M >> K;
  for (int i = 1; i <= N; i++) parents[i] = i;
  while (M--) {
    int i, j, w;

    cin >> i >> j >> w;
    edges.push_back(Edge{i, j, w});
  }
  sort(edges.begin(), edges.end(),
       [](const Edge& a, const Edge& b) { return a.width > b.width; });
  for (Edge& edge : edges) {
    auto& [from, to, width] = edge;

    if (find(from) == find(to)) continue;
    tree[from].push_back({to, width});
    tree[to].push_back({from, width});
    merge(from, to);
  }
  while (K--) {
    int src, dest;

    cin >> src >> dest;
    cout << dfs(0, src, dest, 200) << '\n';
  }
}