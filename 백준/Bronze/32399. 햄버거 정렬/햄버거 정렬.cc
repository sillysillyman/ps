#include <cstdio>
#include <cstring>

int main() {
  char S[4];

  scanf("%s", S);
  printf("%d", !strcmp(S, "(1)") ? 0 : !strcmp(S, ")1(") ? 2 : 1);
}