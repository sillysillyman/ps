#include <iostream>
#include <vector>

using namespace std;

const int LOG = 17;
const int MAX = 100'000;
int depths[MAX + 1];
int parents[MAX + 1][LOG + 1];
vector<int> tree[MAX + 1];

void dfs(int node, int parent) {
  depths[node] = depths[parent] + 1;
  parents[node][0] = parent;
  for (int i = 1; i <= LOG; i++)
    parents[node][i] = parents[parents[node][i - 1]][i - 1];
  for (int child : tree[node]) {
    if (child != parent) dfs(child, node);
  }
}

int lca(int u, int v) {
  if (depths[u] < depths[v]) swap(u, v);
  for (int i = LOG; i >= 0; i--) {
    if (depths[u] - depths[v] >= (1 << i)) u = parents[u][i];
  }
  if (u == v) return u;
  for (int i = LOG; i >= 0; i--) {
    if (parents[u][i] != parents[v][i]) {
      u = parents[u][i];
      v = parents[v][i];
    }
  }
  return parents[u][0];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N, M;

  cin >> N;
  for (int u, v, i = 0; i < N - 1; i++) {
    cin >> u >> v;
    tree[u].push_back(v);
    tree[v].push_back(u);
  }
  dfs(1, 0);
  cin >> M;
  for (int u, v, i = 0; i < M; i++) {
    cin >> u >> v;
    cout << lca(u, v) << '\n';
  }
}