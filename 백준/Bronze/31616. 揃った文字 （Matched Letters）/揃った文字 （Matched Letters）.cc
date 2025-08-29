#include <cstdio>

int main() {
  int N;
  char S[100];
  scanf("%d %s", &N, S);
  for (int i = 1; i < N; i++) if (S[i] != S[i - 1]) return printf("No"), 0;
  printf("Yes");
}