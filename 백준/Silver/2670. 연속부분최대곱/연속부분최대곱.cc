#include <algorithm>
#include <cstdio>

using namespace std;

double dp[10'001];

int main() {
  int N;
  double max_product = 0;

  scanf("%d", &N);
  dp[0] = 1;
  for (int i = 1; i <= N; i++) {
    scanf("%lf", &dp[i]);
    dp[i] = max(dp[i], dp[i - 1] * dp[i]);
    max_product = max(max_product, dp[i]);
  }
  printf("%.3lf", max_product);
}