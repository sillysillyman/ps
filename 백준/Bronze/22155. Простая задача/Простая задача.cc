#include <cstdio>

int n, i, f;

int main() {
  scanf("%d", &n);
  while (n--) {
    scanf("%d%d", &i, &f);
    printf(i < 2 && f < 3 || i < 3 && f < 2 ? "Yes\n" : "No\n");
  }
}