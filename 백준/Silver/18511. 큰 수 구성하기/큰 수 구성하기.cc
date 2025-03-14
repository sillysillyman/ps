#include <cstdio>

int N, K, max_num;
int arr[3];

void dfs(int curr) {
  if (curr > max_num) max_num = curr;
  for (int i = 0; i < K; i++)
    if (int next = 10 * curr + arr[i]; next <= N) dfs(next);
}

int main() {
  scanf("%d%d", &N, &K);
  for (int i = 0; i < K; i++) scanf("%d", &arr[i]);

  dfs(0);
  printf("%d", max_num);
}