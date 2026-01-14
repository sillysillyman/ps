#include <cstdio>

int main() {
  int N;
  scanf("%d", &N);
  putchar("WelcomeToSMUPC"[--N % 14]);
}