#include <cstdio>

int main() {
  int n, m, k, a, b, c, M;
  scanf("%d%d%d%d%d%d", &n, &m, &k, &a, &b, &c);
  n *= a, m *= b, k *= c;
  n >= m && n >= k && printf("Joffrey ");
  m >= n && m >= k && printf("Robb ");
  k >= n && k >= m && printf("Stannis");
}