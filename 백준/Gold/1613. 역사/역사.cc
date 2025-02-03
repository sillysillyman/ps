#include <algorithm>
#include <cstdio>

const int MAX_DIST = 160'000;
int graph[401][401];

int main() {
  int n, k, s;
  scanf("%d%d", &n, &k);

  std::fill(&graph[1][1], &graph[n][n + 1], MAX_DIST);
  for (int i = 1; i <= n; i++) graph[i][i] = 0;

  for (int from, to, i = 0; i < k; i++) {
    scanf("%d%d", &from, &to);
    graph[from][to] = 1;
  }

  for (int k = 1; k <= n; k++)
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
        graph[i][j] = std::min(graph[i][j], graph[i][k] + graph[k][j]);

  scanf("%d", &s);
  for (int from, to, i = 0; i < s; i++) {
    scanf("%d%d", &from, &to);
    printf("%d\n", graph[from][to] == MAX_DIST && graph[to][from] == MAX_DIST
                       ? 0
                   : graph[from][to] && graph[to][from] == MAX_DIST ? -1
                                                                    : 1);
  }
}