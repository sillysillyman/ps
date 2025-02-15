#include <cstdio>

int main() {
  int T;
  scanf("%d", &T);

  while (T--) {
    int N;
    scanf("%d", &N);

    while (N--) {
      int A, B;
      scanf("%d%d", &A, &B);
      printf("%d %d\n", A + B, A * B);
    }
  }
}