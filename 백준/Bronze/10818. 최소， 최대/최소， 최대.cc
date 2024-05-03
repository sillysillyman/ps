#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  int min_val = 1'000'000;
  int max_val = -1'000'000;

  cin >> N;
  for (int num, i = 0; i < N; i++) {
    cin >> num;
    min_val = min(min_val, num);
    max_val = max(max_val, num);
  }
  cout << min_val << ' ' << max_val;
}