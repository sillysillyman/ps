#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int order = 1;
int visited[100001];
vector<int> graph[100001];

void bfs(int src) {
  if (visited[src]) return;

  queue<int> q;

  visited[src] = order++;
  q.push(src);
  while (!q.empty()) {
    int parent = q.front();

    q.pop();
    for (auto& child : graph[parent]) {
      if (!visited[child]) {
        visited[child] = order++;
        q.push(child);
      }
    }
  }
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
  bfs(R);
  for (int i = 1; i <= N; i++) cout << visited[i] << '\n';
}