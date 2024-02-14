#include <cmath>
#include <iostream>

using namespace std;

int main() {
  int X, Y, Z;
  int cnt = -1;

  cin >> X >> Y;
  Z = floor(100 * (double)Y / X);

  int low = 1, high = 1e9;

  while (low <= high) {
    int mid = (low + high) / 2;
    int rate = floor(100 * (double)(Y + mid) / (X + mid));

    if (rate > Z) {
      high = mid - 1;
      cnt = mid;
    } else
      low = mid + 1;
  }
  cout << cnt;
}