#include <cstdio>
#include <cstring>

int main() {
  int N;

  scanf("%d", &N);
  while (N--) {
    char s[1'000];

    scanf("%s", s);
    int len = strlen(s);
    printf("Do-it%s\n",
           (s[len / 2] - '0') ^ (s[len / 2 - 1] - '0') ? "-Not" : "");
  }
}