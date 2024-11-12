#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

int indeg[1'001];
bool visited[1'001];
vector<int> graph[1'001];

int main() {
  int N, M;
  queue<int> q;

  scanf("%d%d", &N, &M);
  while (M--) {
    int n, u = -1, v;

    scanf("%d", &n);
    while (n--) {
      scanf("%d", &v);
      if (u != -1) {
        graph[u].push_back(v);
        ++indeg[v];
      }
      u = v;
    }
  }
  for (int i = 1; i <= N; i++) {
    if (!indeg[i]) {
      q.push(i);
      visited[i] = true;
    }
  }

  vector<int> orders;
  while (!q.empty()) {
    int curr = q.front();

    orders.push_back(curr);
    q.pop();
    for (int next : graph[curr]) {
      if (!visited[next] && !(--indeg[next])) {
        q.push(next);
        visited[next] = true;
      }
    }
  }
  for (int i = 1; i <= N; i++)
    if (!visited[i]) return puts("0"), 0;
  for (int order : orders) printf("%d\n", order);
}