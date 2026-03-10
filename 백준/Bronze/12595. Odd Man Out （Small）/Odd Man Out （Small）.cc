#include <cstdio>
#include <set>

using namespace std;

int main() {
  int N, G, C;
  scanf("%d", &N);
  for (int n = 1; n <= N; n++) {
    set<int> s;
    scanf("%d", &G);
    while (G--) {
      scanf("%d", &C);
      if (s.find(C) == s.end()) s.insert(C);
      else s.erase(C);
    }
    printf("Case #%d: %d\n", n, *s.begin());
  }
}