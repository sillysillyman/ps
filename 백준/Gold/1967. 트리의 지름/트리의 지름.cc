#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int MAX_SIZE = 10'000;
int visited[MAX_SIZE + 1];
vector<pair<int, int>> tree[MAX_SIZE + 1];

void dfs(int node, int weight) {
  if (visited[node]) return;
  visited[node] = weight;
  for (auto& [child, child_weight] : tree[node]) {
    if (!visited[child]) dfs(child, weight + child_weight);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;

  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int parent, child, weight;

    cin >> parent >> child >> weight;
    tree[parent].push_back({child, weight});
    tree[child].push_back({parent, weight});
  }
  dfs(1, 1);

  int endpoint;
  int max_dist = *max_element(visited + 1, visited + n + 1);

  for (int i = 1; i <= n; i++) {
    if (visited[i] == max_dist) endpoint = i;
  }
  fill(visited + 1, visited + n + 1, 0);
  dfs(endpoint, 1);
  cout << *max_element(visited + 1, visited + n + 1) - 1;
}