#include <cstdio>

int count_divisors(int n) {
  int cnt = 0;
  for (int i = 1; i * i <= n; i++)
    if (!(n % i)) cnt += i * i == n ? 1 : 2;
  return cnt;
}

int main() {
  int C;
  scanf("%d", &C);
  while (C--) {
    int L, U, max_cnt = 0;
    scanf("%d%d", &L, &U);
    for (int i = L; i <= U; i++)
      if (int cnt = count_divisors(i); cnt > max_cnt) max_cnt = cnt;
    printf("%d\n", max_cnt);
  }
}