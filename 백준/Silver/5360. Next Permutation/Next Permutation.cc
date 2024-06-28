#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;

  cin >> N;
  while (N--) {
    string A;

    cin >> A;
    if (next_permutation(A.begin(), A.end()))
      cout << A << '\n';
    else
      cout << "USELESS\n";
  }
}