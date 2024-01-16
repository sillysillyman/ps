#include <iostream>
#include <queue>
#include <vector>

using namespace std;

bool visited[1001];
vector<pair<int, int>> tree[1001];

void bfs(int src, int dst) {
  queue<pair<int, int>> q;

  q.push({src, 0});
  visited[src] = true;
  while (!q.empty()) {
    auto [cur, dist] = q.front();

    if (cur == dst) {
      cout << dist << '\n';
      break;
    }
    q.pop();
    for (auto child : tree[cur]) {
      if (!visited[child.first]) {
        visited[child.first] = true;
        q.push({child.first, dist + child.second});
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N, M;

  cin >> N >> M;
  for (int i = 0; i < N - 1; i++) {
    int src, dst, dist;

    cin >> src >> dst >> dist;
    tree[src].push_back({dst, dist});
    tree[dst].push_back({src, dist});
  }
  for (int i = 0; i < M; i++) {
    int src, dst;

    fill(visited + 1, visited + N + 1, false);
    cin >> src >> dst;
    bfs(src, dst);
  }
}