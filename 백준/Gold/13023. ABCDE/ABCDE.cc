#include <cstdio>
#include <vector>

using namespace std;

bool visited[2'000];
vector<int> graph[2'000];

bool dfs(int curr, int depth) {
  bool flag = false;

  if (depth >= 5) return true;

  visited[curr] = true;
  for (int& next : graph[curr]) {
    if (visited[next]) continue;
    flag |= dfs(next, depth + 1);
  }
  visited[curr] = false;

  return flag;
}

int main() {
  int N, M;

  scanf("%d%d", &N, &M);
  while (M--) {
    int u, v;
    scanf("%d%d", &u, &v);
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  bool flag = false;
  for (int i = 0; i < N; i++) {
    flag |= dfs(i, 1);
    if (flag) break;
  }
  printf("%d", flag);
}