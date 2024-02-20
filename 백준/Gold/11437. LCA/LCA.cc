#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node {
  int parent, depth = 0;
  vector<int> connected;
};

bool visited[100'001];
Node tree[100'001];

void bfs(int root) {
  queue<int> q;

  visited[root] = true;
  q.push(root);
  tree[root].depth = 0;
  while (!q.empty()) {
    int parent = q.front();
    int depth = tree[parent].depth;

    q.pop();
    for (int child : tree[parent].connected) {
      if (visited[child]) continue;
      visited[child] = true;
      q.push(child);
      tree[child].depth = depth + 1;
      tree[child].parent = parent;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N, M;

  cin >> N;
  for (int u, v, i = 1; i <= N - 1; i++) {
    cin >> u >> v;
    tree[u].connected.push_back(v);
    tree[v].connected.push_back(u);
  }
  bfs(1);
  cin >> M;
  for (int u, v, i = 0; i < M; i++) {
    cin >> u >> v;
    while (tree[u].depth > tree[v].depth) u = tree[u].parent;
    while (tree[u].depth < tree[v].depth) v = tree[v].parent;
    while (u != v) {
      u = tree[u].parent;
      v = tree[v].parent;
    }
    cout << u << '\n';
  }
}