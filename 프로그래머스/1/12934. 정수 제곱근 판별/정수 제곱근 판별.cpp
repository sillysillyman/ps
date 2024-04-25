#include <cmath>
#include <iostream>

using namespace std;
using ll = long long;

ll solution(ll n) {
  return (ll)sqrt(n) * (ll)sqrt(n) == n ? pow((ll)sqrt(n) + 1, 2) : -1;
}