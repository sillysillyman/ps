#include <cstdio>

int main() {
  int n;

  scanf("%d", &n);
  long long prev = 1, curr = 1, next = 1;
  for (int i = 4; i <= n; i++) {
    long long tmp = prev;

    prev = curr;
    curr = next;
    next += tmp;
  }
  printf("%lld", next);
}