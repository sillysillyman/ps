#include <cstdio>
#include <cstring>

int n, c, bedroom, balcony, total;

int main() {
  scanf("%d%d", &n, &c);
  while (n--) {
    int a;
    char t[9];

    scanf("%d%s", &a, t);
    total += a;
    if (!strcmp(t, "bedroom"))
      bedroom += a;
    else if (!strcmp(t, "balcony"))
      balcony += a;
  }
  printf("%d\n%d\n%.6f", total, bedroom, c * (double)(total - 0.5 * balcony));
}