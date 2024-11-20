#include <algorithm>
#include <bitset>
#include <cstdio>

using namespace std;

int N;
char S[11];
bitset<10> arr[1'024];

int get_reversed(bitset<10>& b) {
  int ret = 0;
  for (int i = 0; i < N; i++) ret = (ret << 1) | b[i];
  return ret;
}

int main() {
  scanf("%d %s", &N, S);
  for (int i = 0; i < 1 << N; i++) arr[i] = bitset<10>(i);

  sort(arr, arr + (1 << N), [](bitset<10> a, bitset<10> b) {
    int cnt_a = 0, cnt_b = 0;
    for (int i = 0; i < N; i++) {
      cnt_a += a[i];
      cnt_b += b[i];
    }
    if (cnt_a == cnt_b) return get_reversed(a) < get_reversed(b);
    return cnt_a < cnt_b;
  });

  for (int i = 0; i < 1 << N; i++) {
    if (bitset<10>(S) == arr[i]) {
      printf("%d\n", i);
      break;
    }
  }
}