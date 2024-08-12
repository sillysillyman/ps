#include <cstdio>
#include <cstring>

int main() {
  while (true) {
    int root = 0;
    char digits[1'001];

    scanf("%s", digits);
    if (!strcmp(digits, "0")) break;
    for (int len = strlen(digits), i = 0; i < len; i++) root += digits[i] - '0';
    while (root > 9) {
      int digit_sum = 0;

      while (root) {
        digit_sum += root % 10;
        root /= 10;
      }
      root = digit_sum;
    }
    printf("%d\n", root);
  }
}