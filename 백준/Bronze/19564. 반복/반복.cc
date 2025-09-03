#include <cstdio>

int main() {
  int K = 1;
  char S[100001];
  scanf("%s", S);
  for (int i = 1; S[i]; i++) K += S[i - 1] >= S[i];
  printf("%d", K);
}