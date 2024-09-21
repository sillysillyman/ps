#include <cstdio>
#include <cstring>

int main() {
  char N[20];

  scanf("%s", N);
  for (int i = 0; N[i]; i++) {
    if (i == strlen(N) / 2) putchar(' ');
    printf("%c", N[i]);
  }
}