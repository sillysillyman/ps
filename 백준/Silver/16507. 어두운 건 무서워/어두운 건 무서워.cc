#include <iostream>

using namespace std;

int photo[1000][1000];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int R, C, Q;
  int r1, c1, r2, c2;

  cin >> R >> C >> Q;
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      cin >> photo[i][j];
      if (j != 0) photo[i][j] += photo[i][j - 1];
    }
  }
  while (Q--) {
    cin >> r1 >> c1 >> r2 >> c2;
    r1--, c1--, r2--, c2--;

    int brightness = 0;

    for (int i = r1; i <= r2; i++) {
      if (c1 == 0)
        brightness += photo[i][c2];
      else
        brightness += photo[i][c2] - photo[i][c1 - 1];
    }
    brightness /= (r2 - r1 + 1) * (c2 - c1 + 1);
    cout << brightness << '\n';
  }
}