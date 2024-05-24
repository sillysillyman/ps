#include <cstdio>

int main() {
  int M, K;

  scanf("%d %d", &M, &K);
  printf("%s", M % K ? "No" : "Yes");
}