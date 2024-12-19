#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int main() {
  int n;
  int arr[11];

  fill(arr + 1, arr + 11, 1);

  while (scanf("%d", &n) && n) {
    char s[5];

    scanf("%*s %s", s);

    if (!strcmp(s, "on")) {
      printf("%s\n", arr[n] ? "Stan may be honest" : "Stan is dishonest");
      fill(arr + 1, arr + 11, 1);
    } else if (!(strcmp(s, "low")))
      fill(arr + 1, arr + n + 1, 0);
    else
      fill(arr + n, arr + 11, 0);
  }
}