#include <cstdio>
#include <map>

using namespace std;

map<int, pair<int, int>> dp;

int sum(int x, int depth) {
  if (!depth) return x;
  if (dp.find(x) == dp.end()) dp[x] = {x / 2, (x + 1) / 2};
  return x + sum(dp[x].first, depth - 1) + sum(dp[x].second, depth - 1);
}

int main() {
  int X, M;

  scanf("%d%d", &X, &M);
  printf("%d", sum(X, M));
}