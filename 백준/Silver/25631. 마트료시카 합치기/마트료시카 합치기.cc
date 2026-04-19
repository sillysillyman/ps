#include <cstdio>
#include <map>

int main() {
  int N, M = 0, x;
  std::map<int, int> m;
  scanf("%d", &N);
  while (N--) {
    scanf("%d", &x);
    m[x]++;
    M = M > m[x] ? M : m[x];
  }
  printf("%d", M);
}