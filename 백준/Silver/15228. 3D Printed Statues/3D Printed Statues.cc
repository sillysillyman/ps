#include <cmath>
#include <cstdio>

int main() {
  int n;

  scanf("%d", &n);
  if (int log = (int)log2(n); log == log2(n))
    printf("%d", log + 1);
  else
    printf("%d", log + 2);
}