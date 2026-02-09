#include <cstdio>
#include <cstring>

const char *s[] = {"Never gonna give you up", "Never gonna let you down", "Never gonna run around and desert you", "Never gonna make you cry", "Never gonna say goodbye", "Never gonna tell a lie and hurt you", "Never gonna stop"};

int main() {
  int N, f;
  char S[51];
  scanf("%d", &N);
  while (N--) {
    f = 0;
    scanf(" %[^\n]", S);
    for (int i = 0; i < 7; i++)
      if (!strcmp(S, s[i])) f = 1;
    if (!f) return puts("Yes"), 0;
  }
  puts("No");
}