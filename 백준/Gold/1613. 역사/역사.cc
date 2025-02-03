#include <algorithm>
#include <cstdio>

const int MAX_DIST = 160'000;
int dist[401][401];
int graph[401][401];

int main() {
  int n, k, s;
  scanf("%d%d", &n, &k);

  std::fill(&dist[1][1], &dist[n][n + 1], MAX_DIST);
  for (int i = 1; i <= n; i++) dist[i][i] = 0;

  for (int from, to, i = 0; i < k; i++) {
    scanf("%d%d", &from, &to);
    graph[from][to] = 1;
    dist[from][to] = 1;
  }

  for (int k = 1; k <= n; k++)
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
        dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);

  scanf("%d", &s);
  for (int from, to, i = 0; i < s; i++) {
    scanf("%d%d", &from, &to);
    printf("%d\n", dist[from][to] == MAX_DIST && dist[to][from] == MAX_DIST ? 0
                   : dist[from][to] && dist[to][from] == MAX_DIST           ? -1
                                                                  : 1);
  }
}