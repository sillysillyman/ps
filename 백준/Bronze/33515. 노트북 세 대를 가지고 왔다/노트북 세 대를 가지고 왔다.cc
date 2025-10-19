#include <cstdio>

int main() {
  int T1, T2;
  scanf("%d%d", &T1, &T2);
  printf("%d", T1 <= T2 ? T1 : T2);
}