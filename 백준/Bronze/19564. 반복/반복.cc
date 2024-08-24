#include <cstdio>

int main() {
  int L, K = 1;
  char S[100'001];

  scanf("%s", S);
  for (int i = 1; S[i] != '\0'; i++) {
    if (S[i - 1] >= S[i]) ++K;
  }
  printf("%d", K);
}