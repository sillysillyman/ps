#include <cstdio>

int main() {
  int N, M;
  scanf("%d%d", &N, &M);
  printf("%s", 100 * N >= M ? "Yes" : "No");
}