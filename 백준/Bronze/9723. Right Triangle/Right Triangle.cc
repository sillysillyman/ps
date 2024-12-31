#include <algorithm>
#include <cstdio>

int sides[3];

int main() {
  int T;
  scanf("%d", &T);

  for (int t = 1; t <= T; t++) {
    for (int i = 0; i < 3; i++) scanf("%d", &sides[i]);
    std::sort(sides, sides + 3);
    printf("Case #%d: %s\n", t,
           sides[2] * sides[2] == sides[0] * sides[0] + sides[1] * sides[1]
               ? "YES"
               : "NO");
  }
}