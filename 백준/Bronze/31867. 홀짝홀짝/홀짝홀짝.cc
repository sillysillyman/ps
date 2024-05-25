#include <iostream>

using namespace std;

char num[1'000'000];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, odd_cnt = 0;

  cin >> N >> num;
  for (int i = 0; i < N; i++) odd_cnt += (num[i] - '0') & 1;
  cout << (2 * odd_cnt == N ? -1 : (2 * odd_cnt < N ? 0 : 1));
}