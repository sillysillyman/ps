#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int Q;

  cin >> Q;
  while (Q--) {
    int a;

    cin >> a;
    cout << !(a & (a - 1)) << '\n';
  }
}