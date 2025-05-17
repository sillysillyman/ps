#include <cstdio>

int main() {
  int n;
  scanf("%d", &n);
  while (n--) {
    int z = 0, m = 0;
    for (int x, i = 0; i < 10; i++) {
      scanf("%d", &x);
      printf("%d ", x);
      z += x == 17;
      m += x == 18;
    }
    printf("\n%s\n\n", z && m ? "both" : z ? "zack" : m ? "mack" : "none");
  }
}