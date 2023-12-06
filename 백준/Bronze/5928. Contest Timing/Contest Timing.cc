#include <iostream>

using namespace std;

int main() {
  int D, H, M;

  cin >> D >> H >> M;
  M >= 11 ? M -= 11 : (M += 49, H--);
  H >= 11 ? H -= 11 : (H += 13, D--);
  D -= 11;
  if (D < 0) {
    cout << -1;
    return 0;
  }
  cout << 60 * 24 * D + 60 * H + M;
}