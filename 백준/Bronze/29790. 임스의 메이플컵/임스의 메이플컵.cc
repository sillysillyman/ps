#include <cstdio>

int main() {
  int N, U, L;
  scanf("%d%d%d", &N, &U, &L);
  printf("%s", N > 999 && (U > 7999 || L > 259) ? "Very Good" : N > 999 ? "Good" : "Bad");
}