#include <cstdio>

int main() {
  int L, K = 1;
  char S[100'001];

  scanf("%s", S);
  for (int i = 1; S[i] != '\0'; i++) K += S[i - 1] >= S[i];
  printf("%d", K);
}