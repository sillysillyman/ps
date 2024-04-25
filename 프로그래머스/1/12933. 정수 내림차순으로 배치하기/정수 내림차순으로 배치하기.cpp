#include <algorithm>
#include <iostream>

using namespace std;
using ll = long long;

ll solution(ll n) {
  string answer = to_string(n);

  sort(answer.begin(), answer.end(), greater());
  return stol(answer);
}