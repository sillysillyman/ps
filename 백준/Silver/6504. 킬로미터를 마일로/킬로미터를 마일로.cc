#include <cstdio>

int main() {
  int t;
  int fibo[22] = {1, 2};

  for (int i = 2; i < 22; i++) fibo[i] = fibo[i - 2] + fibo[i - 1];
  scanf("%d", &t);
  while (t--) {
    int x, y = 0;

    scanf("%d", &x);
    for (int i = 21; i > 0; i--) {
      if (x >= fibo[i]) {
        x -= fibo[i];
        y += fibo[i - 1];
      }
    }
    printf("%d\n", y);
  }
}