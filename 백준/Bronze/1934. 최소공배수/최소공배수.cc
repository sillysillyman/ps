#include <iostream>
#include <numeric>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int T;

  cin >> T;
  while (T--) {
    int A, B;

    cin >> A >> B;
    cout << lcm(A, B) << '\n';
  }
}