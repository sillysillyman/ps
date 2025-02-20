#include <cstdio>

int main() {
  int t = 1;
  char a, b;
  while (scanf(" %c %c", &a, &b) && !(a == '#' && b == '#')) {
    printf("Case %d\n", t++);

    int n;
    scanf("%d", &n);
    while (n--) {
      char s[256];
      scanf(" %[^\n]", s);
      for (int i = 0; s[i]; i++) {
        if (s[i] == a || s[i] == b || s[i] + 'a' - 'A' == a ||
            s[i] + 'a' - 'A' == b)
          printf("_");
        else
          printf("%c", s[i]);
      }
      printf("\n");
    }
    printf("\n");
  }
}