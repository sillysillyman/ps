#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, M, max_depth = 0;

  cin >> N >> M;
  vector<bool> visited(N + 1);
  vector<int> nodes;
  vector<vector<int>> graph(N + 1);

  for (int src, dest, i = 0; i < M; i++) {
    cin >> src >> dest;
    graph[src].push_back(dest);
    graph[dest].push_back(src);
  }

  queue<pair<int, int>> q;
  q.push({1, 0});
  visited[1] = true;
  while (!q.empty()) {
    auto [curr, depth] = q.front();

    if (depth == max_depth)
      nodes.push_back(curr);
    else if (depth > max_depth) {
      max_depth = depth;
      nodes.clear();
      nodes.push_back(curr);
    }
    q.pop();
    for (int next : graph[curr]) {
      if (visited[next]) continue;
      visited[next] = true;
      q.push({next, depth + 1});
    }
  }
  cout << *min_element(nodes.begin(), nodes.end()) << ' ' << max_depth << ' '
       << nodes.size();
}