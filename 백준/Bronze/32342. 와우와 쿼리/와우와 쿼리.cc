#include <cstdio>

int main() {
  int Q, n;
  char S[1001];
  scanf("%d", &Q);
  while (Q--) {
    n = 0;
    scanf("%s", S);
    for (int i = 0; S[i + 2]; i++)
      if ((S[i] & S[i + 2]) == 87 && S[i + 1] == 79) n++;
    printf("%d\n", n);
  }
}
