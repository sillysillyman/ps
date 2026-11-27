#include <algorithm>
#include <cstdio>
#include <cstring>

int cnt[5];
char S[1000];
const char* T = "uospc";

int main() {
  scanf("%*d%s", S);
  for (char* p = S; *p; p++)
    if (const char* q = strchr(T, *p)) cnt[q - T]++;
  printf("%d", *std::min_element(cnt, cnt + 5));
}
