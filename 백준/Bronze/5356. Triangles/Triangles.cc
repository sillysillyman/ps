#include <cstdio>

int main() {
  int t;

  scanf("%d", &t);
  while (t--) {
    char ch;
    int size;

    scanf("%d %c", &size, &ch);
    for (int i = 1; i <= size; i++) {
      for (int j = 0; j < i; j++) printf("%c", ch);
      printf("\n");
      ++ch;
      if (ch > 'Z') ch -= 26;
    }
    printf("\n");
  }
}