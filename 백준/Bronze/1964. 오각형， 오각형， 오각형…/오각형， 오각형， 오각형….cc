#include <iostream>

using namespace std;

const int MOD = 45'678;

int main() {
  int N, cnt = 5, diff = 7;

  cin >> N;
  for (int i = 2; i <= N; i++) {
    cnt += diff;
    cnt %= MOD;
    diff += 3;
  }
  cout << cnt;
}