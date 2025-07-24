#include <cstdio>

int T, cnt;

int main() {
  scanf("%d", &T);
  for (int x, i = 0; i < 5; i++) {
    scanf("%d", &x);
    cnt += x == T;
  }
  printf("%d", cnt);
}