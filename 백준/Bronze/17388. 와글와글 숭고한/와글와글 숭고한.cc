#include <cstdio>

int main() {
  int S, K, H;
  scanf("%d%d%d", &S, &K, &H);
  printf("%s", S + K + H > 99   ? "OK"
               : S < K && S < H ? "Soongsil"
               : K < S && K < H ? "Korea"
                                : "Hanyang");
}