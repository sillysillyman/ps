#include <cstdio>
#include <cstring>

int main() {
  char s[201];
  scanf("%s", s);
  printf("%c", s[strlen(s) - 2]);
}