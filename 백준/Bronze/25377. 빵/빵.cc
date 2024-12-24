#include <cstdio>

int main() {
  int N, t = 1'000;

  scanf("%d", &N);
  while (N--) {
    int A, B;

    scanf("%d%d", &A, &B);
    t = t > B && A <= B ? B : t;
  }
  printf("%d", t == 1'000 ? -1 : t);
}