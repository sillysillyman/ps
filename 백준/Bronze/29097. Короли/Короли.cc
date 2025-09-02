#include <cstdio>

int main() {
  int n, m, k, a, b, c, M;
  scanf("%d%d%d%d%d%d", &n, &m, &k, &a, &b, &c);
  n *= a, m *= b, k *= c;
  M = n > m && n > k ? n : m > k ? m : k;
  n == M && printf("Joffrey ");
  m == M && printf("Robb ");
  k == M && printf("Stannis");
}