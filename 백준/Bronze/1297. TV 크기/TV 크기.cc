#include <cmath>
#include <iostream>

using namespace std;

int main() {
  int D, H, W;

  cin >> D >> H >> W;
  cout << (int)(sqrt((double)H * H * D * D / (W * W + H * H))) << ' '
       << (int)(sqrt((double)W * W * D * D / (W * W + H * H)));
}