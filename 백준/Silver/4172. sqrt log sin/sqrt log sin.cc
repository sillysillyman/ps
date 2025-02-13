#include <cmath>
#include <cstdio>

const int MOD = 1e6;
int dp[MOD + 1];

int main() {
  int i;
  dp[0] = 1;
  for (i = 1; i < MOD; i++)
    dp[i] = (dp[(int)(i - sqrt(i))] + dp[(int)log(i)] +
             dp[(int)(i * sin(i) * sin(i))]) %
            MOD;

  while (scanf("%d", &i) && ~i) printf("%d\n", dp[i]);
}