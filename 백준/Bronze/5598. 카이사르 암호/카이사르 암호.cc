#include <cstdio>

int main() {
  char cipher[1'001];

  scanf("%s", cipher);
  for (int i = 0; cipher[i]; i++)
    printf("%c", 'A' + (cipher[i] - 'A' + 23) % 26);
}