#include <cstdio>

int main() {
  int P, Q, n = 0, m = 0;
  int v[6000], w[6000];
  scanf("%d%d", &P, &Q);
  for (int i = 1; i <= P; i++)
    if (!(P % i))
      v[n++] = i;
  for (int i = 1; i <= Q; i++)
    if (!(Q % i))
      w[m++] = i;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      printf("%d %d\n", v[i], w[j]);
}