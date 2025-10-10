#include <cstdio>

int main() {
  char s[4];
  scanf("%s", s);
  printf("%c%c%c%c", 69^73^s[0], 78^83^s[1], 70^84^s[2], 74^80^s[3]);
}