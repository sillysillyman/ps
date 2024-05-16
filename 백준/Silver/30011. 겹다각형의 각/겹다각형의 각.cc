#include <iostream>

using namespace std;

int main() {
  int N, sum = 0;

  cin >> N;
  while (N--) {
    int A;

    cin >> A;
    sum += 180 * A;
  }
  cout << sum - 360;
}