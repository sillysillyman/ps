#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int visited[1001];
vector<pair<int, int>> tree[1001];

void bfs(int src, int dst) {
  queue<pair<int, int>> q;

//   cout << "src: " << src << ", dst: " << dst << '\n';
  q.push({src, 0});
  visited[src] = true;
  while (!q.empty()) {
    auto [cur, dist] = q.front();

    // cout << "cur: " << cur << ", dist: " << dist << '\n';
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

    fill(visited, visited + 1001, 0);
    cin >> src >> dst;
    bfs(src, dst);
  }
}