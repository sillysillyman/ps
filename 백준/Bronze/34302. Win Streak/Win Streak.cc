#include <cstdio>

int N, S, T, W, w, f;

int main() {
  scanf("%d", &N);
  while (N--) {
    scanf("%d%d", &S, &T);
    S > T ? (w = f ? w + 1 : 1, f = 1) : (w = f = 0);
    if (w > W) W = w;
  }
  printf("%d", W);
}