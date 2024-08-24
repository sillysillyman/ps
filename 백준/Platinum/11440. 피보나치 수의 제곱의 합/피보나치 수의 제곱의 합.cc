#include <cstdio>

using ll = long long;

const int MOD = 1'000'000'007;

struct Matrix {
  ll e11, e12, e21, e22;

  Matrix operator*(const Matrix& other) {
    return Matrix{((e11 * other.e11) % MOD + (e12 * other.e21) % MOD) % MOD,
                  ((e11 * other.e12) % MOD + (e12 * other.e22) % MOD) % MOD,
                  ((e21 * other.e11) % MOD + (e22 * other.e21) % MOD) % MOD,
                  ((e21 * other.e12) % MOD + (e22 * other.e22) % MOD) % MOD};
  }
};

Matrix power(Matrix mat, ll n) {
  if (n == 0 || n == 1) return mat;

  Matrix res = power(mat, n / 2);
  res = res * res;
  if (n & 1) res = res * mat;
  return res;
}

int main() {
  ll n;

  scanf("%lld", &n);

  Matrix base = {1, 1, 1, 0};
  ll fibo1 = power(base, n + 1).e21;
  ll fibo2 = power(base, n).e21;
  if (n == 0) {
    printf("0");
    return 0;
  }
  printf("%lld", ((fibo1 * fibo1) % MOD - (fibo2 * fibo2) % MOD +
                  (n & 1 ? 1 : -1) + MOD) %
                     MOD);
}