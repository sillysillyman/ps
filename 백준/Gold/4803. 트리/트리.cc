#include <iostream>
#include <vector>

using namespace std;

bool visited[501];
vector<int> graph[501];

bool dfs(int node, int parent) {
  if (visited[node]) return false;

  bool is_tree = true;

  visited[node] = true;
  for (int child : graph[node]) {
    if (child != parent) is_tree &= dfs(child, node);
  }
  return is_tree;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t = 1;

  while (true) {
    int n, m, cnt = 0;

    cin >> n >> m;
    if (n == 0 && m == 0) break;
    cnt = 0;
    fill(visited + 1, visited + n + 1, false);
    for (int i = 1; i <= n; i++) graph[i].clear();
    for (int node1, node2, i = 0; i < m; i++) {
      cin >> node1 >> node2;
      graph[node1].push_back(node2);
      graph[node2].push_back(node1);
    }
    for (int i = 1; i <= n; i++) {
      if (dfs(i, 0)) cnt++;
    }
    cout << "Case " << t << ": ";
    if (cnt == 0)
      cout << "No trees.\n";
    else if (cnt == 1)
      cout << "There is one tree.\n";
    else
      cout << "A forest of " << cnt << " trees.\n";
    t++;
  }
}