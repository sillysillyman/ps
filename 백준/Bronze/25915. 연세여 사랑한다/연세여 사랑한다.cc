#include <cstdio>

int main() {
  char start;

  scanf("%c", &start);
  printf("%d", ('I' > start ? 'I' - start : start - 'I') + 84);
}