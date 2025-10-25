#include <cstdio>

int main() {
  int N, M, A, B;
  scanf("%d%d%d%d", &N, &M, &A, &B);
  printf("%d", M >= 3 * N ? 0 : (3 * N - M) * A + B);
}