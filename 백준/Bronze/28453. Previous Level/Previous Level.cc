#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;

  cin >> N;
  while (N--) {
    int M;

    cin >> M;
    if (M == 300)
      cout << 1 << ' ';
    else if (275 <= M)
      cout << 2 << ' ';
    else if (250 <= M)
      cout << 3 << ' ';
    else
      cout << 4 << ' ';
  }
}