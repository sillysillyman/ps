#include <iostream>

using namespace std;

int arr[100];
long long dp[21][100];

int main() {
  int N;
  long long cnt = 0;

  cin >> N;
  for (int i = 0; i < N; i++) cin >> arr[i];
  for (int i = 0; i < N; i++) {
    if (i == 0)
      dp[arr[i]][i]++;
    else {
      for (int j = 0; j < 21; j++) {
        if (dp[j][i - 1] && j + arr[i] <= 20) dp[j + arr[i]][i] += dp[j][i - 1];
        if (dp[j][i - 1] && j - arr[i] >= 0) dp[j - arr[i]][i] += dp[j][i - 1];
      }
    }
  }
  cout << dp[arr[N - 1]][N - 2];
}