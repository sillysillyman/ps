#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int Q;

  cin >> Q;
  while (Q--) {
    long long a, b;

    cin >> a >> b;
    cout << (2 * a <= b && !(b % a)) << '\n';
  }
}