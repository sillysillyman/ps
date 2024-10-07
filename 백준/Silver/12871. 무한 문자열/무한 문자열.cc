#include <cstdio>
#include <cstring>
#include <numeric>

using namespace std;

char s[101], t[101], temp_s[2451], temp_t[2451];

int main() {
  scanf("%s%s", s, t);

  int len_s = strlen(s), len_t = strlen(t);
  int n = lcm(len_s, len_t);

  while (strlen(temp_s) < n) strcat(temp_s, s);
  while (strlen(temp_t) < n) strcat(temp_t, t);
  printf("%d", !strcmp(temp_s, temp_t));
}