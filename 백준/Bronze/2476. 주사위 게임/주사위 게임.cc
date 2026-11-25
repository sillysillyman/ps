#include <algorithm>
#include <cstdio>

using namespace std;

int main() {
  int N, M = 0;
  scanf("%d", &N);
  while (N--) {
    int d[3];
    scanf("%d%d%d", &d[0], &d[1], &d[2]);
    sort(d, d + 3);
    int v = d[0] == d[2]                   ? 1000 * (10 + d[0])
            : d[0] == d[1] || d[1] == d[2] ? 100 * (10 + d[1])
                                           : 100 * d[2];
    M = max(M, v);
  }
  printf("%d", M);
}
