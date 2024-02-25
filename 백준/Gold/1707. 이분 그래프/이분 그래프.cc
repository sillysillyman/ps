#include <iostream>
#include <vector>

using namespace std;

const int MAX_V = 20'000;
int visited[MAX_V + 1];
vector<int> graph[MAX_V + 1];

bool dfs(int node, int parent, int visit) {
  if (visited[node] != 0 && visited[node] != visited[parent]) return true;
  if (visited[node] != 0 && visited[node] == visited[parent]) return false;
  visited[node] = visit;

  bool is_bipartite = true;

  for (auto next : graph[node]) {
    if (next != parent) is_bipartite &= dfs(next, node, -visit);
  }
  return is_bipartite;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int K;

  cin >> K;
  while (K--) {
    bool is_bipartite = true;
    int V, E;

    cin >> V >> E;
    fill(visited + 1, visited + V + 1, 0);
    for (int i = 1; i <= V; i++) graph[i].clear();
    for (int u, v, i = 0; i < E; i++) {
      cin >> u >> v;
      graph[u].push_back(v);
      graph[v].push_back(u);
    }
    for (int i = 1; i <= V; i++) is_bipartite &= dfs(i , 0 ,1);
    if (is_bipartite)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}