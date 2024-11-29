#include <cstdio>

int main() {
  int P, S;

  while (scanf("%d%d", &P, &S) && P && S) {
    int T1, T2, T3, N, winner = 0;
    bool trapped[10] = {};
    int pos[10] = {};

    scanf("%d%d%d%d", &T1, &T2, &T3, &N);

    int p = 0;
    while (N--) {
      int D1, D2;

      p %= P;
      while (trapped[p]) {
        trapped[p++] = false;
        p %= P;
      }
      scanf("%d%d", &D1, &D2);
      pos[p] += D1 + D2;
      if (!winner && pos[p] > S) winner = p + 1;
      if (pos[p] == T1 || pos[p] == T2 || pos[p] == T3) trapped[p] = true;
      ++p;
    }
    printf("%d\n", winner);
  }
}