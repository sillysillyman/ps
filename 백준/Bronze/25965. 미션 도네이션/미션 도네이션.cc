#include <cstdio>

struct KDA {
  long long K, D, A;
};

KDA m[100];

int main() {
  int N, M, k, d, a;
  scanf("%d", &N);
  while (N--) {
    long long n = 0;
    scanf("%d", &M);
    for (int i = 0; i < M; i++)
      scanf("%lld%lld%lld", &m[i].K, &m[i].D, &m[i].A);
    scanf("%d%d%d", &k, &d, &a);
    for (int i = 0; i < M; i++)
      if (long long c = k * m[i].K - d * m[i].D + a * m[i].A; c > 0) n += c;
    printf("%lld\n", n);
  }
}