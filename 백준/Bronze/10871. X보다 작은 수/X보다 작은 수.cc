#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);

  int N, X;

  cin >> N >> X;
  while (N--) {
    int num;

    cin >> num;
    if (num < X) cout << num << ' ';
  }
}