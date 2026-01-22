#include <cstdio>

int N, a, c;

int main() {
  scanf("%d", &N);
  while (N--) {
    scanf("%d", &a);
    a % 2 ? ++c : --c;
  }
  printf("%d", c < 2u);
}