#include <cstdio>

int main() {
  int N;

  scanf("%d", &N);
  while (N--) {
    int M;

    scanf("%d", &M);
    if (M == 300)
      printf("1 ");
    else if (275 <= M)
      printf("2 ");
    else if (250 <= M)
      printf("3 ");
    else
      printf("4 ");
  }
}