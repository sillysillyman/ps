#include <cstdio>

char digits[1001];

int main() {
  while (scanf("%s", digits) && digits[0] != '0') {
    int root = 0;

    for (int i = 0; digits[i] != '\0'; i++) root += digits[i] - '0';
    printf("%d\n", (root - 1) % 9 + 1);
  }
}