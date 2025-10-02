#include <cstdio>

long long K[100], D[100], A[100];

int main() {
  int N, M, k, d, a;
  scanf("%d", &N);
  while (N--) {
    long long n = 0;
    scanf("%d", &M);
    for (int i = 0; i < M; i++) scanf("%lld%lld%lld", &K[i], &D[i], &A[i]);
    scanf("%d%d%d", &k, &d, &a);
    for (int i = 0; i < M; i++)
      if (long long c = k * K[i] - d * D[i] + a * A[i]; c > 0) n += c;
    printf("%lld\n", n);
  }
}