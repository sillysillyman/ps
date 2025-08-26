#include <cstdio>

int main() {
  int T, x, q;
  float p;
  scanf("%d", &T);
  while (T--) {
    float s = 0;
    scanf("%d", &x);
    while (x--) {
      scanf("%*s%d%f", &q, &p);
      s += q * p;
    }
    printf("$%.2f\n", s);
  }
}