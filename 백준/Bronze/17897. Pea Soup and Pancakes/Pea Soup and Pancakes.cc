#include <cstdio>
#include <cstring>

int main() {
  bool printed = false;
  int n;

  scanf("%d", &n);
  while (n--) {
    int k;
    bool found[2] = {false, false};
    char name[101], menu[101];

    scanf("%d %[^\n]", &k, name);
    while (k--) {
      scanf(" %[^\n]", menu);
      if (!strcmp(menu, "pea soup"))
        found[0] = true;
      else if (!strcmp(menu, "pancakes"))
        found[1] = true;
    }
    if (!printed && found[0] && found[1]) {
      printed = true;
      printf("%s", name);
    }
  }
  if (!printed) puts("Anywhere is fine I guess");
}