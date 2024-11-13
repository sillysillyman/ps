#include <iostream>
#include <queue>

using namespace std;

bool visited[200'001];
int indeg[200'001];
pair<int, int> graph[200'001];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;

  cin >> N;
  for (int i = 1; i <= N; ++i) {
    int u, v;
    cin >> u >> v;
    graph[i].first = u;
    graph[i].second = v;
    ++indeg[u];
    ++indeg[v];
  }

  int cnt = N;
  queue<int> q;
  for (int i = 1; i <= N; ++i) {
    if (indeg[i] < 2) {
      visited[i] = true;
      q.push(i);
      --cnt;
    }
  }
  while (!q.empty()) {
    int curr = q.front();

    q.pop();

    auto [next1, next2] = graph[curr];
    if (!visited[next1] && --indeg[next1] < 2) {
      visited[next1] = true;
      q.push(next1);
      --cnt;
    }
    if (!visited[next2] && --indeg[next2] < 2) {
      visited[next2] = true;
      q.push(next2);
      --cnt;
    }
  }

  cout << cnt << '\n';
  for (int i = 1; i <= N; i++)
    if (!visited[i]) cout << i << ' ';
}