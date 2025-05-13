#include <cstdio>

int arr[26];

int main() {
  char c;
  while (scanf("%c", &c) && c != '\n') arr[c - 'a'] = 1;
  while (scanf("%c", &c) && c != '\n')
    if (!arr[c - 'a']) printf("%c", c);
}