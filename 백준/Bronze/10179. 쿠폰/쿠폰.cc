#include <cstdio>

int main() {
  int T;

  scanf("%d", &T);
  while (T--) {
    double dollar;

    scanf("%lf", &dollar);
    printf("$%.2lf\n", 0.8 * dollar);
  }
}