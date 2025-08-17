#include <cstdio>

int N, n;

int main() {
  scanf("%d", &N);
  while (N--) {
    char c;
    scanf(" %c", &c);
    c == 'o' ? ++n : n = 0;
    if (n == 3) return printf("Yes"), 0;
  }
  printf("No");
}