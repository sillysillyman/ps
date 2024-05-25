#include <cstdio>

int main() {
  char ch;

  scanf("%c", &ch);
  printf("%d", ('I' > ch ? 'I' - ch : ch - 'I') + 84);
}