#include <cstdio>
#include <cstring>

char P[1'000'001], S[1'000'001];

int main() {
  scanf("%s %s", S, P);
  printf("%d", strstr(S, P) != nullptr);
}