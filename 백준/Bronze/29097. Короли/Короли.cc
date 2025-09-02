#include <cstdio>

int main() {
  int n, m, k, a, b, c, M;
  scanf("%d%d%d%d%d%d", &n, &m, &k, &a, &b, &c);
  n *= a, m *= b, k *= c;
  M = n > m && n > k ? n : m > k ? m : k;
  if (n == M) printf("Joffrey ");
  if (m == M) printf("Robb ");
  if (k == M) printf("Stannis");
}