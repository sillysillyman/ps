#include <iostream>
#include <algorithm>

using namespace std;

int sequence[100000];
int dp[100000];

int main() {
  int N;

  cin >> N;
  for (int i = 0; i < N; i++) cin >> sequence[i];
  dp[0] = 1;
  for (int i = 1; i < N; i++) {
    int res = 1;
    int curr = sequence[i];

    for (int j = i - 1; j >= 0; j--) {
      if (sequence[j] == curr - 1) {
        res++;
        curr--;
      }
    }
    dp[i] = res;
  }
//   for (int i = 0; i < N; i++) cout << dp[i] << ' ';
  cout << *max_element(dp, dp + N);
}