#include <cstdio>

int main() {
  int N;
  scanf("%d", &N);
  printf("%s", !(N % 2024) && N <= 1e5 ? "Yes" : "No");
}