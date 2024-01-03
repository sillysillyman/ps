#include <iostream>

using namespace std;

struct fraction {
  int quotient, numerator, denominator;
};

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

fraction add(fraction a, fraction b) {
  int quotient, numerator, denominator;

  quotient = a.quotient + b.quotient;
  numerator = a.numerator * b.denominator + b.numerator * a.denominator;
  denominator = a.denominator * b.denominator;

  int divisor = gcd(numerator, denominator);

  if (divisor != 1) {
    numerator /= divisor;
    denominator /= divisor;
  }
  if (numerator >= denominator) {
    quotient += numerator / denominator;
    numerator %= denominator;
  }
  return fraction{quotient, numerator, denominator};
}

void print_fraction(fraction f) {
  if (f.numerator == 0) {
    cout << f.quotient << '\n';
    return;
  }

  string fraction_bar;

  for (int i = 0; i < to_string(f.denominator).length(); i++)
    fraction_bar += "-";
  if (f.quotient == 0) {
    cout << f.numerator << '\n';
    cout << fraction_bar << '\n';
    cout << f.denominator << '\n';
  } else {
    string space = " ";

    for (int i = 0; i < to_string(f.quotient).length(); i++) space += " ";
    cout << space << f.numerator << '\n';
    cout << f.quotient << ' ' << fraction_bar << '\n';
    cout << space << f.denominator << '\n';
  }
}

int main() {
  int N;

  while (cin >> N) {
    fraction total_expectation = {0, 0, 1};

    for (int i = N; i >= 1; i--) {
      fraction ith_expectation = {0, N, i};
      total_expectation = add(total_expectation, ith_expectation);
    }
    print_fraction(total_expectation);
  }
}