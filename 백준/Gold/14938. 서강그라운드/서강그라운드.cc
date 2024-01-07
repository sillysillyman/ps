#include <iostream>

using namespace std;

const int MAX_LENGTH = 1500;
int items[100];
int graph[100][100];

int main() {
  int n, m, r;

  cin >> n >> m >> r;
  fill(&graph[0][0], &graph[n - 1][n], MAX_LENGTH);
  for (int i = 0; i < n; i++) graph[i][i] = 0;
  for (int i = 0; i < n; i++) cin >> items[i];
  while (r--) {
    int a, b, l;

    cin >> a >> b >> l;
    a--, b--;
    graph[a][b] = l;
    graph[b][a] = l;
  }
  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
    }
  }
//   cout << '\n';
//   for (int i = 0; i < n; i++) {
//     for (int j = 0; j < n; j++) cout << graph[i][j] << ' ';
//     cout << '\n';
//   }
  int max_cnt = 0;
  for (int i = 0; i < n; i++) {
    int cnt = 0;

    for (int j = 0; j < n; j++) {
      if (graph[i][j] <= m)
        cnt += items[j];
    }
    max_cnt = max(max_cnt, cnt);
  }
  cout << max_cnt;
}