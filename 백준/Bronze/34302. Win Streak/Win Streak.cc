#include <cstdio>

bool flag;
int N, S, T, W, w;

int main() {
  scanf("%d", &N);
  while (N--) {
    scanf("%d%d", &S, &T);
    if (S > T) {
      w = flag ? w + 1 : 1;
      flag = 1;
    } else {
      w = 0;
      flag = 0;
    }
    if (w > W) W = w;
  }
  printf("%d", W);
}