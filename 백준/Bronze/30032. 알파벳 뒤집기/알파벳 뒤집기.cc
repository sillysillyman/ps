#include <cstdio>

int main() {
  int N, D;

  scanf("%d%d", &N, &D);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      char ch;
      scanf(" %c", &ch);
      if (D == 1)
        printf("%c", ch == 'b' ? 'p' : ch == 'd' ? 'q' : ch == 'p' ? 'b' : 'd');
      else
        printf("%c", ch == 'b' ? 'd' : ch == 'd' ? 'b' : ch == 'p' ? 'q' : 'p');
    }
    putchar('\n');
  }
}