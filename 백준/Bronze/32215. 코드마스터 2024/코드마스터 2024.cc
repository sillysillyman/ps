# include <cstdio>

int main() {
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  printf("%d", m * k + m * !!(n - k));
}