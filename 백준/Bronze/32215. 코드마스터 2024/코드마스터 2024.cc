# include <cstdio>

int main() {
  int m, k;
  scanf("%*d%d%d", &m, &k);
  printf("%d", m * ++k);
}