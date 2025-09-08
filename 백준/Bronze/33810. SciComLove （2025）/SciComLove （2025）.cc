#include <cstdio>

int cnt;
char S[11];
char T[11] = "SciComLove";

int main() {
  scanf("%s", S);
  for (int i = 0; i < 11; i++)
    cnt += S[i] != T[i];
  printf("%d", cnt);
}