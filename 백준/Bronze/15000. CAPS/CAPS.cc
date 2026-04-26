#include <cstdio>

int main() {
  int c;
  while ((c = getchar()) != EOF) if (c != '\n') putchar(c - 32);
}