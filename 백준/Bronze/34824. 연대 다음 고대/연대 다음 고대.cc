#include <cstdio>
#include <cstring>

int N;
char s[51];

int main() {
  scanf("%d", &N);
  while (N--) {
    scanf("%s", s);
    if (!strcmp(s, "korea")) return printf("Yonsei Lost..."), 0;
    else if (!strcmp(s, "yonsei")) return printf("Yonsei Won!"), 0;
  }
}