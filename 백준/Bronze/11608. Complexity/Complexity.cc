#include <algorithm>
#include <cstdio>
#include <numeric>

using namespace std;

int cnts[26];

int main() {
  char c;

  while ((c = getchar()) && c != '\n') ++cnts[c - 'a'];

  int n = 0;
  for (int i = 0; i < 26; i++) n += cnts[i] > 0;
  if (n < 3) return putchar('0'), 0;
  sort(cnts, cnts + 26);
  printf("%d", accumulate(cnts, cnts + 26, 0) - cnts[24] - cnts[25]);
}