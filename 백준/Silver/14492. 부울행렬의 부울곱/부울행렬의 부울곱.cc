#include <cstdio>

int A[300][300], B[300][300];

int main() {
  int N, cnt = 0;

  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) scanf("%d", &A[i][j]);
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) scanf("%d", &B[i][j]);
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      bool res = false;

      for (int k = 0; k < N; k++) {
        res |= A[i][k] & B[k][j];
        if (res) {
          ++cnt;
          break;
        }
      }
    }
  }
  printf("%d", cnt);
}