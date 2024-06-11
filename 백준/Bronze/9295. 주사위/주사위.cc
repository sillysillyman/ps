#include <cstdio>

int main() {
  int T;

  scanf("%d", &T);
  for (int t = 1; t <= T; t++) {
    int dice1, dice2;

    scanf("%d %d", &dice1, &dice2);
    printf("Case %d: %d\n", t, dice1 + dice2);
  }
}