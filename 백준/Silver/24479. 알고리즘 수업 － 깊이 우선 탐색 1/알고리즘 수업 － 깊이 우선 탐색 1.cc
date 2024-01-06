#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int order = 1;
int visited[100001];
vector<int> graph[100001];

void dfs(int src) {
  if (visited[src]) return;
  visited[src] = order;
  order++;
  for (auto child : graph[src]) dfs(child);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N, M, R;

  cin >> N >> M >> R;
  while (M--) {
    int u, v;

    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  for (int i = 1; i <= N; i++) sort(graph[i].begin(), graph[i].end());
  dfs(R);
  for (int i = 1; i <= N; i++) cout << visited[i] << '\n';
}