#include <cstdio>
#include <numeric>

const int MOD = 1e9 + 7;

struct Matrix {
  long long e11, e12, e21, e22;

  Matrix operator%(int mod) const {
    return {e11 % mod, e12 % mod, e21 % mod, e22 % mod};
  }

  Matrix operator*(const Matrix& other) const {
    return Matrix{e11 * other.e11 + e12 * other.e21,
                  e11 * other.e12 + e12 * other.e22,
                  e21 * other.e11 + e22 * other.e21,
                  e21 * other.e12 + e22 * other.e22} %
           MOD;
  }

  Matrix power(long long e) {
    if (!e) return {1, 0, 0, 1};
    if (e == 1) return *this;

    Matrix half = this->power(e / 2);

    return e & 1 ? half * half * (*this) : half * half;
  }
};

int main() {
  long long n, m;
  scanf("%lld%lld", &n, &m);

  Matrix base = {1, 1, 1, 0};
  printf("%lld", base.power(std::gcd(n, m) - 1).e11);
}