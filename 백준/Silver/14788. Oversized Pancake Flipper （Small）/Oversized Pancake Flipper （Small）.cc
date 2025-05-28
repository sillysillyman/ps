#include <cstdio>
#include <cstring>

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; t++) {
    int K, cnt = 0;
    char S[11];
    scanf("%s%d", S, &K);

    for (int i = 0; i <= strlen(S) - K; i++) {
      if (S[i] == '+') continue;
      for (int j = i; j < i + K; j++)
        S[j] = S[j] == '+' ? '-' : '+';
      ++cnt;
    }

    bool flag = false;
    for (int i = 0; S[i]; i++)
      if (S[i] == '-') flag = true;
      
    printf("Case #%d: ", t);
    if (flag)
      printf("IMPOSSIBLE\n");
    else
      printf("%d\n", cnt);
  }
}