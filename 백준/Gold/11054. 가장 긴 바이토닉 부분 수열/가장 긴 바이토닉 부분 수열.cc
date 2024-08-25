#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

int lis_v[1'000];
int lis_w[1'000];

int main() {
  int N;

  scanf("%d", &N);
  vector<int> v(N);
  vector<int> w(N);
  for (int num, i = 0; i < N; i++) {
    scanf("%d", &num);
    v[i] = num;
    w[i] = num;
  }
  reverse(w.begin(), w.end());
  for (int i = 0; i < N; i++) {
    lis_v[i] = 1;
    lis_w[i] = 1;
    for (int j = 0; j < i; j++) {
      if (v[j] < v[i]) lis_v[i] = max(lis_v[i], lis_v[j] + 1);
      if (w[j] < w[i]) lis_w[i] = max(lis_w[i], lis_w[j] + 1);
    }
  }

  int max_bitonic_len = 1;

  for (int i = 0; i < N; i++)
    max_bitonic_len = max(max_bitonic_len, lis_v[i] + lis_w[N - i - 1] - 1);
  printf("%d", max_bitonic_len);
}