#include <cstdio>

int main() {
  int N;
  scanf("%d", &N);
  while (N--) {
    int a, b;
    scanf("%d%d", &a, &b);

    printf("y = %dx + %d\n", a, b);
    for (int i = 10 * a + b; i >= 0; i--) {
      for (int j = 0; j < 11; j++)
        printf("%c", i == 0 || j == 0 || i == a * j + b ? '*' : ' ');
      printf("\n");
    }
  }
}