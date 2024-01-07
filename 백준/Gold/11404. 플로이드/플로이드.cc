#include <iostream>

using namespace std;

const int MAX_COST = 10000000;
int graph[100][100];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;

  cin >> n >> m;
  fill(&graph[0][0], &graph[n - 1][n], MAX_COST);
  for (int i = 0; i < n; i++) graph[i][i] = 0;
  while (m--) {
    int a, b, c;

    cin >> a >> b >> c;
    a--, b--;
    graph[a][b] = min(graph[a][b], c);
  }
//   for (int i = 0; i < n; i++) {
//     for (int j = 0; j < n; j++) {
//     //   if (graph[i][j] >= MAX_COST) cout << 0 << ' ';
//     //   else cout << graph[i][j] << ' ';
//       cout << graph[i][j] << ' ';
//     }
//     cout << '\n';
//   }
  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (graph[i][j] >= MAX_COST) cout << 0 << ' ';
      else cout << graph[i][j] << ' ';
    }
    cout << '\n';
  }
}