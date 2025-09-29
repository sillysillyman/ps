#include <cstdio>

int N;
char b[64];

int main() {
  scanf("%d", &N);
  while (N--) {
    int e = 0;
    scanf("%s", b);
    for (int c = 0, i = 0; b[i]; i++)
      (i + 1) % 8 ? c += b[i] == '1' : (e += (c & 1 && b[i] == '0') || (!(c & 1) && b[i] == '1'), c = 0);
    printf("%d\n", e);
  }
}