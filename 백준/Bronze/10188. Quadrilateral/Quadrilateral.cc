#include <cstdio>

int main() {
  int N;
  scanf("%d", &N);
  while (N--) {
    int c, r;
    scanf("%d%d", &c, &r);
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) printf("%c", 'X');
      printf("\n");
    }
    printf("\n");
  }
}