#include <cstdio>
#include <cstring>

char s[100'001], t[100'001];

int main() {
  while (~scanf(" %s %s", s, t)) {
    int j = 0;
    for (int i = 0; t[i]; i++)
      if (s[j] == t[i]) ++j;
    printf("%s\n", j == strlen(s) ? "Yes" : "No");
  }
}