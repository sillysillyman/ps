#include <cstdio>

int main() {
  int b, w, p, n;
  scanf("%d%d%d%d", &b, &w, &p, &n);
  printf("%s", w < ++b ? "Watermelon" : p < b ? "Pomegranates" : n < b ? "Nuts" : "Nothing");
}