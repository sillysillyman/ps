#include <cstdio>

char S[26];

int main() {
  int N;
  scanf("%d", &N);

  if (N < 26) {
    scanf("%s", S);
    printf("%s", S);
  } else {
    fgetc(stdin);
    fread(S, 1, 11, stdin);

    char c;
    bool flag = false;
    int cnt = 0;
    int middle = N - 22;

    for (int i = 0; i < N - 22; i++) {
      c = fgetc(stdin);
      if (c == '.') {
        if (i == 0 || i == N - 23) flag = true;
        ++cnt;
      }
    }

    fread(S + 14, 1, 11, stdin);

    if (!cnt || (cnt == 1 && flag))
      for (int i = 11; i < 14; i++) S[i] = '.';
    else
      for (int i = 9; i < 15; i++) S[i] = '.';

    printf("%s", S);
  }
}