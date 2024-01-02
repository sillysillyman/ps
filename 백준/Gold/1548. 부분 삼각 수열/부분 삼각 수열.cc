#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  int N;
  int sequence[50];

  cin >> N;
  for (int i = 0; i < N; ++i) cin >> sequence[i];
  if (N < 3) {
    cout << N;
    return 0;
  }
  sort(sequence, sequence + N);
//   for (int i = 0; i < N; ++i) cout << sequence[i] << ' ';
//   cout << '\n';
  
  int cnt, max_cnt = 0;

  for (int i = 0; i < N - 2; i++) {
    // cout << "i: " << i << '\n';
    cnt = 2;
    for (int j = i + 2; j < N; j++) {
      if (sequence[i] + sequence[i + 1] > sequence[j]) cnt++;
    }
    max_cnt = max(max_cnt, cnt);
    // cout << "max_cnt: " << max_cnt << '\n';
  }
  cout << max_cnt;
}