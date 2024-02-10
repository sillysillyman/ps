#include <iostream>

using namespace std;

char original[100][100];

int main() {
  int cnt = 0;
  int n, m;

  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) cin >> original[i][j];
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      char pixel;

      cin >> pixel;
      if (pixel == original[i][j]) cnt++;
    }
  }
  cout << cnt;
}