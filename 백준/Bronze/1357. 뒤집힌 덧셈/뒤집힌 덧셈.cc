#include <iostream>

using namespace std;

int rev(int n) {
  int ret = 0;

  while (n != 0) {
    ret += n % 10;
    n /= 10;
    ret *= 10;
  }
  ret /= 10;
  return ret;
}

int main() {
  int X, Y;

  cin >> X >> Y;
  cout << rev(rev(X) + rev(Y));
}