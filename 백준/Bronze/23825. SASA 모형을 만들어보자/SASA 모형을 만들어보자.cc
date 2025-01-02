#include <algorithm>
#include <cstdio>

int main() {
  int N, M;
  scanf("%d%d", &N, &M);
  printf("%d", std::min(N, M) / 2);
}