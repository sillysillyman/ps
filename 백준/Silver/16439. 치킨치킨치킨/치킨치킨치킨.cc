#include <algorithm>
#include <cstdio>

using namespace std;

bool flag[30];
int table[30][30];

int main() {
  int N, M;

  scanf("%d%d", &N, &M);
  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++) scanf("%d", &table[i][j]);
  flag[0] = flag[1] = flag[2] = true;

  int max_sum = 0;
  do {
    int sum = 0;

    for (int i = 0; i < N; i++) {
      int val = 0;
      for (int j = 0; j < M; j++)
        if (flag[j]) val = max(val, table[i][j]);
      sum += val;
    }
    max_sum = max(max_sum, sum);
  } while (prev_permutation(flag, flag + M));
  printf("%d", max_sum);
}