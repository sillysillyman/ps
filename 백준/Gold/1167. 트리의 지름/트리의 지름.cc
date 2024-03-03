#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

const int MAX_V = 100'000;
int diameter;
int max_diameter = 0;
ll visited[MAX_V + 1];
vector<pair<int, int>> tree[MAX_V + 1];

void dfs(int node, ll dist) {
  if (visited[node]) return;
  visited[node] = dist;
  for (auto& [child, child_dist] : tree[node]) {
    if (!visited[child]) {
      dfs(child, dist + child_dist); 
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int V;

  cin >> V;
  for (int i = 1; i <= V; i++) {
    int node;

    cin >> node;
    while (true) {
      int child;
      ll dist;
      
      cin >> child;
      if (child == -1) break;
      cin >> dist;
      tree[node].push_back({child, dist});
    }
  }
  dfs(1, 1);
//   for (int i = 1; i <= V; i++) cout << visited[i] << ' ';
//   cout << '\n';

  int endpoint;
  ll max_dist = 0;

  for (int i = 1; i <= V; i++) {
    if (visited[i] >= max_dist) {
      endpoint = i;
      max_dist = visited[i];
    }
  }
  fill(visited + 1, visited + V + 1, 0);
//   visited[max_idx] = 0;
  dfs(endpoint, 1);
//   for (int i = 1; i <= V; i++) cout << visited[i] << ' ';
  cout << *max_element(visited + 1, visited + V + 1) - 1;
}