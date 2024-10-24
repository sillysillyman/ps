#include <cstdio>

int main() {
  int N, D;

  scanf("%d%d", &N, &D);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      char c;
      scanf(" %c", &c);
      if (D == 1)
        printf("%c", c == 'b' ? 'p' : c == 'd' ? 'q' : c == 'p' ? 'b' : 'd');
      else
        printf("%c", c == 'b' ? 'd' : c == 'd' ? 'b' : c == 'p' ? 'q' : 'p');
    }
    printf("\n");
  }
}