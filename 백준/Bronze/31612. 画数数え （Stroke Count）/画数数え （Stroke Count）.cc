#include <cstdio>

int n;
char S[101];

int main() {
  scanf("%*d%s", S);
  for (int i = 0; S[i]; i++) n += 1 + (S[i] == 'i' || S[i] == 'j');
  printf("%d", n);
}