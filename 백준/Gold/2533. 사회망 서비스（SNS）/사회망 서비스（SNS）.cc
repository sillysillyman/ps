#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 1'000'000;
int dp[MAX_N + 1][2];
bool visited[MAX_N + 1];
vector<int> graph[MAX_N + 1];

void dfs(int curr) {
  dp[curr][0] = 0;
  dp[curr][1] = 1;
  visited[curr] = true;
  for (auto next : graph[curr]) {
    if (visited[next]) continue;
    dfs(next);
    dp[curr][0] += dp[next][1];
    dp[curr][1] += min(dp[next][0], dp[next][1]);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;

  cin >> N;
  for (int u, v, i = 0; i < N - 1; i++) {
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  dfs(1);
  cout << min(dp[1][0], dp[1][1]);
}