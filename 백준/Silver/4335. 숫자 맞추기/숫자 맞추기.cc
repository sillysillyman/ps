#include <cstdio>

int arr[11];

int main() {
  int n;

  while (scanf("%d", &n) && n) {
    char c;

    scanf("%*s %c%*s", &c);

    if (c == 'o') {
      printf("%s\n", !arr[n] ? "Stan may be honest" : "Stan is dishonest");
      for (int i = 1; i < 11; i++) arr[i] = 0;
    } else if (c == 'l')
      for (int i = 1; i <= n; i++) arr[i] = 1;
    else
      for (int i = n; i <= 10; i++) arr[i] = 1;
  }
}