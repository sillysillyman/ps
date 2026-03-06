#include <cmath>
#include <cstdio>

int main() {
  int n;
  scanf("%d", &n);
  printf("%d", 5 - abs(4 - --n % 8));
}