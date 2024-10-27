#include <cstdio>

int main() {
  int A, B, digit, cnt = 0;

  scanf("%d %d %d", &A, &B, &digit);
  for (int i = A; i <= B; i++) {
    int num = 10;
    for (int j = 0; j < 4; j++, num *= 10)
      if (i % num / (num / 10) == digit) ++cnt;
  }
  printf("%d", cnt);
}