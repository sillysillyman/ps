#include <iostream>

using namespace std;

long long sum, ans;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  cin >> N;

  for (int num, i = 0; i < N; i++) {
    cin >> num;
    ans += sum * num;
    sum += num;
  }
  cout << ans;
}