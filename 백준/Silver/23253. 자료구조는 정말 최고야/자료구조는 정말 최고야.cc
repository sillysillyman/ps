#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  bool success = true;
  int N, M;

  cin >> N >> M;
  for (int k, i = 0; i < M; i++) {
    cin >> k;

    for (int prev = -1, curr, j = 0; j < k; j++) {
      cin >> curr;
      if (prev != -1 && prev < curr) success = false;
      prev = curr;
    }
  }
  cout << (success ? "Yes" : "No");
}