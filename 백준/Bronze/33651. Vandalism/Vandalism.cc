#include <cstdio>

char s[4];
int arr[26];

int main() {
  scanf("%s", s);
  for (int i = 0; s[i]; i++) ++arr[s[i] - 'A'];
  for (char c : "UAPC") {
    if (c == '\0') break;
    if (!arr[c - 'A']) printf("%c", c);
  }
}