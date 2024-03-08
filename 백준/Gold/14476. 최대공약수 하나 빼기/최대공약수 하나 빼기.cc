#include <iostream>

using namespace std;

int arr[1000000], LtoR[1000000], RtoL[1000000];

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N, K;
  int max_gcd = 0;

  cin >> N;
  for (int i = 0; i < N; i++) cin >> arr[i];
  LtoR[0] = arr[0];
  for (int i = 1; i < N; i++) LtoR[i] = gcd(LtoR[i - 1], arr[i]);
  RtoL[N - 1] = arr[N - 1];
  for (int i = N - 2; i >= 0; i--) RtoL[i] = gcd(RtoL[i + 1], arr[i]);
  for (int i = 0; i < N; i++) {
    if (i == 0) {
      if (RtoL[1] > max_gcd) {
        K = arr[0];
        max_gcd = RtoL[1];
      }
    } else if (i == N - 1) {
      if (LtoR[N - 2] > max_gcd) {
        K = arr[N - 2];
        max_gcd = LtoR[N - 2];
      }
    } else {
      if (int new_gcd = gcd(LtoR[i - 1], RtoL[i + 1]); new_gcd > max_gcd) {
        K = arr[i];
        max_gcd = new_gcd;
      }
    }
  }
  if (K % max_gcd == 0)
    cout << -1;
  else
    cout << max_gcd << ' ' << K;
}