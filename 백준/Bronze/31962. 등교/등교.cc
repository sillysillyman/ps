#include <cstdio>

int N, X, S, T, max_S = -1;

int main() {
  scanf("%d%d", &N, &X);
  while (N--) {
    scanf("%d%d", &S, &T);
    if (S + T <= X && S > max_S) max_S = S;
  }
  printf("%d", max_S);
}