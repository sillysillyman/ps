#include <cstdio>

char S[200'001];

int main() {
  int N, K;

  scanf("%d%d%s", &N, &K, S);
  for (int i = 0; i < N && K > 0; i++) {
    if (int diff = 'Z' - S[i] + 1; diff <= K && S[i] != 'A') {
      S[i] = 'A';
      K -= diff;
    }
  }
  if (K > 0) S[N - 1] = 'A' + ((S[N - 1] - 'A' + K) % 26);
  printf("%s", S);
}