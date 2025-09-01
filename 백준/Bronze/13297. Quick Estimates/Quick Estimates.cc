#include <cstdio>
#include <cstring>

int main() {
  int N;
  char S[101];
  scanf("%d", &N);
  while (N--) {
    scanf(" %s", S);
    printf("%ld\n", strlen(S));
  }
}