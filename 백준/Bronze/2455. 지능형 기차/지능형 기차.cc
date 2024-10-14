#include <cstdio>

int n, max_n;

int main() {
  for (int out, in, i = 0; i < 4; i++) {
    scanf("%d%d", &out, &in);
    n += in - out;
    if (n > max_n) max_n = n;
  }
  printf("%d", max_n);
}