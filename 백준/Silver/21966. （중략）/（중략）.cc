#include <cstdio>

char S[100'001];

int main() {
  int N;

  scanf("%d %s", &N, S);
  if (N < 26)
    printf("%s", S);
  else {
    int cnt = 0;
    for (int i = 11; i < N - 11; i++)
      if (S[i] == '.') ++cnt;
    if (!cnt || (cnt == 1 && (S[11] == '.' || S[N - 12] == '.')))
      printf("%.11s...%.11s", S, S + N - 11);
    else
      printf("%.9s......%.10s", S, S + N - 10);
  }
}