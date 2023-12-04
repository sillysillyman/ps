#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  int T;

  cin >> T;
  while (T--) {
    int A[10];

    for (int i = 0; i < 10; i++) cin >> A[i];
    sort(A, A + 10, greater<>());
    cout << A[2] << '\n';
  }
}