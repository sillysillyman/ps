#include <cstdio>

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; t++) {
    int m, n, k;
    char words[50][6];
    scanf("%d", &m);
    for (int i = 0; i < m; i++) scanf("%s", words[i]);
    scanf("%d", &n);

    printf("Scenario #%d:\n", t);
    for (int i = 0; i < n; i++) {
      scanf("%d", &k);
      for (int idx, j = 0; j < k; j++) {
        scanf("%d", &idx);
        printf("%s", words[idx]);
      }
      printf("\n");
    }
    printf("\n");
  }
}