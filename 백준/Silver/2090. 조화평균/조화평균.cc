#include <cstdio>
#include <numeric>

using ll = long long;

struct Fraction {
  ll numerator, denominator;

  Fraction operator+(const Fraction& other) const {
    ll b = denominator * other.denominator;
    ll a = numerator * other.denominator + other.numerator * denominator;
    ll d = std::gcd(a, b);
    return Fraction{a / d, b / d};
  }
};

int main() {
  int N;
  Fraction f = {0, 1};

  scanf("%d", &N);
  for (int num, i = 0; i < N; i++) {
    scanf("%d", &num);
    f = f + Fraction{1, num};
  }
  printf("%lld/%lld", f.denominator, f.numerator);
}