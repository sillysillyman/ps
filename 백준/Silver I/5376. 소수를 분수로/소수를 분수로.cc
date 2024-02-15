#include <iostream>
#include <string>

using namespace std;
using ll = long long;

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int T;

  cin >> T;
  while (T--) {
    ll numerator, denominator, divisor;
    string decimal;

    cin >> decimal;
    decimal = decimal.substr(2);
    if (decimal.find('(') == string::npos) {
      numerator = stoi(decimal);
      denominator = 1;
      for (int i = 0; i < decimal.length(); i++) denominator *= 10;
    } else {
      int cycle_start = decimal.find('(');
      int cycle_end = decimal.find(')');

      numerator = 0;
      for (int i = 0; i < decimal.length(); i++) {
        if (i == cycle_start || i == cycle_end) continue;
        numerator *= 10;
        numerator += decimal[i] - '0';
      }

      ll not_cycle = 0;

      for (int i = 0; i < cycle_start; i++) {
        not_cycle *= 10;
        not_cycle += decimal[i] - '0';
      }
      numerator -= not_cycle;
      denominator = 9;
      for (int i = 0; i < cycle_end - cycle_start - 2; i++)
        denominator = 10 * denominator + 9;
      for (int i = 0; i < cycle_start; i++) denominator *= 10;
    }
    divisor = gcd(numerator, denominator);
    cout << numerator / divisor << '/' << denominator / divisor << '\n';
  }
}