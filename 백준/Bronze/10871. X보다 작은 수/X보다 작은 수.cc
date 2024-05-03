#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, X;

  cin >> N >> X;
  while (N--) {
    int num;

    cin >> num;
    if (num < X) cout << num << ' ';
  }
}