#include <iostream>

using namespace std;
using ll = long long;

int main() {
  int cnt = 0;
  ll N, r;

  cin >> N;
  r = N / 2;

  int x = 0, y = r;
  int dx[3] = {0, 1, 1};
  int dy[3] = {-1, 0, -1};

  while (x != y) {
    for (int i = 0; i < 3; i++) {
      ll nx = (ll)(x + dx[i]);
      ll ny = (ll)(y + dy[i]);

      if ((nx - 1) * (nx - 1) + (ny - 1) * (ny - 1) < r * r &&
          r * r < nx * nx + ny * ny) {
        cnt++;
        x = nx, y = ny;
        break;
      }
    }
  }
  cout << 8 * cnt - 4;
}