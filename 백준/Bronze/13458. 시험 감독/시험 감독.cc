#include <iostream>

using namespace std;

int arr[(int)1e6];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, B, C;
  long long cnt = 0;
  cin >> N;
  for (int i = 0; i < N; i++) cin >> arr[i];
  cin >> B >> C;

  for (int i = 0; i < N; i++) {
    arr[i] -= arr[i] < B ? arr[i] : B;
    cnt += arr[i] / C + !!(arr[i] % C) + 1;
  }

  cout << cnt;
}