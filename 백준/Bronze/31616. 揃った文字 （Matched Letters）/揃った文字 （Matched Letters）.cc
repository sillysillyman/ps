#include <cstdio>

int main() {
  int N;
  char a, b;
  scanf("%d %c", &N, &a);
  while (--N) {
    scanf("%c", &b);
    if (a != b) return printf("No"), 0;
  }
  printf("Yes");
}