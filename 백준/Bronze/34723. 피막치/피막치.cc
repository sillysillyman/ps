#include <algorithm>
#include <cstdio>

int main() {
  int P, M, C, X, m = 1e9;
  scanf("%d%d%d%d", &P, &M, &C, &X);
  for (int i = 1; i <= P; i++)
    for (int j = 1; j <= M; j++)
      for (int k = 1; k <= C; k++) m = std::min(m, abs((i + j) * (j + k) - X));
  printf("%d", m);
}