#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  while (true) {
    int a, b, c;

    cin >> a >> b >> c;
    if (a == 0 && b == 0 && c == 0) break;
    if (a > b) swap(a, b);
    if (b > c) swap(b, c);
    if (a * a + b * b == c * c)
      cout << "right\n";
    else
      cout << "wrong\n";
  }
}