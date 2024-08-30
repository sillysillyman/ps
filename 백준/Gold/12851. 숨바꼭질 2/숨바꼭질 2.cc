#include <cstdio>
#include <queue>

using namespace std;

const int MAX_N = 100'000;
int N, K;
pair<int, int> graph[MAX_N + 1];

void bfs(int src) {
  queue<int> q;

  q.push(src);
  graph[src] = {0, 1};
  while (!q.empty()) {
    int x = q.front();
    auto [time, cnt] = graph[x];

    q.pop();
    if (time > graph[K].first) continue;
    if (x > 0) {
      if (graph[x - 1].first > time + 1) {
        graph[x - 1] = {time + 1, cnt};
        q.push(x - 1);
      } else if (graph[x - 1].first == time + 1)
        graph[x - 1].second += cnt;
    }
    if (x < MAX_N) {
      if (graph[x + 1].first > time + 1) {
        graph[x + 1] = {time + 1, cnt};
        q.push(x + 1);
      } else if (graph[x + 1].first == time + 1)
        graph[x + 1].second += cnt;
    }
    if (2 * x <= MAX_N) {
      if (graph[2 * x].first > time + 1) {
        graph[2 * x] = {time + 1, cnt};
        q.push(2 * x);
      } else if (graph[2 * x].first == time + 1)
        graph[2 * x].second += cnt;
    }
  }
}

int main() {
  scanf("%d%d", &N, &K);
  for (int i = 0; i < MAX_N + 1; i++) graph[i].first = MAX_N;
  bfs(N);
  printf("%d\n%d", graph[K].first, graph[K].second);
}