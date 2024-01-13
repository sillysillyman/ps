#include <iostream>

using namespace std;

long long sums[1000001];
long long accumulated[1000001];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int T;

  for (int i = 1; i < 1000001; i++) {
    for (int j = 1; i * j < 1000001; j++) {
      sums[i * j] += i;
    }
    if (i == 1)
      accumulated[i] = sums[i];
    else
      accumulated[i] = accumulated[i - 1] + sums[i];
  }
  cin >> T;
  while (T--) {
    int N;

    cin >> N;
    cout << accumulated[N] << '\n';
  }
}