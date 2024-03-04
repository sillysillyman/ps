#include <iostream>

using namespace std;

int main() {
  int T;

  cin >> T;
  while (T--) {
    int N;
    int sum = 0;

    cin >> N;
    for (int num, i = 0; i < N; ++i) {
      cin >> num;
      sum += num;
    }
    cout << sum << '\n';
  }
}