#include <cstdio>

int main() {
  int T, N, K;
  int A[1000];
  scanf("%d", &T);
  for (int t = 1; t <= T; t++) {
    int c = 0;
    scanf("%d%d", &N, &K);
    for (int i = 0; i < N; i++) scanf("%d", &A[i]);
    for (int i = 0; i <= N - K; i++) {
      int f = 1;
      for (int j = 0; j < K; j++) {
        if (A[i + j] != K - j) {
          f = 0;
          break;
        }
      }
      c += f;
    }
    printf("Case #%d: %d\n", t, c);
  }
}