#include <iostream>

using namespace std;

int relationship[100][100];

int main() {
  int n, m;
  int person1, person2;

  cin >> n >> person1 >> person2 >> m;
  person1--, person2--;
  fill(&relationship[0][0], &relationship[n][n + 1], 10000);
  for (int i = 0; i < n; i++) relationship[i][i] = 0;
  for (int i = 0; i < m; i++) {
    int x, y;

    cin >> x >> y;
    x--, y--;
    relationship[x][y] = 1;
    relationship[y][x] = 1;
  }
  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) relationship[i][j] = min(relationship[i][j], relationship[i][k] + relationship[k][j]);
    }
  }
  cout << (relationship[person1][person2] == 10000 ? -1 : relationship[person1][person2]);
}