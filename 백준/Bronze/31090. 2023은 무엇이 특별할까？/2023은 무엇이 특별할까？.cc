#include <cstdio>

int main() {
  int T, N;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &N);
    printf((N + 1) % (N % 100) ? "Bye\n" : "Good\n");
  }
}