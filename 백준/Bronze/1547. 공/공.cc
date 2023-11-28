#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int M, X, Y;
  int cups[3] = {1, 2, 3};

  cin >> M;
  while (M--) {
    cin >> X >> Y;

    int idx_x, idx_y;

    for (int i = 0; i < 3; i++) {
      if (cups[i] == X) idx_x = i;
      if (cups[i] == Y) idx_y = i;
    }
    swap(cups[idx_x], cups[idx_y]);
  }
  cout << cups[0];
}