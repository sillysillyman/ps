#include <cstdio>

int main() {
  int n, m, c = 0;
  char s[16];
  scanf("%d%d", &n, &m);
  while (n--) {
    int f = 1;
    int arr[26] = {0};
    scanf("%s", s);
    for (int i = 0; s[i]; i++) {
      int j = s[i] - 'A';
      arr[j]++;
      f &= arr[j] < 2 && j < m;
    }
    c += f;
  }
  printf("%d", c);
}