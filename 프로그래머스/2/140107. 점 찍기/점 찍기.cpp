#include <cmath>
#include <vector>

using namespace std;
using ll = long long;

ll solution(int k, int d) {
  ll answer = 0;

  for (int x = 0; x <= d; x += k) {
    int max_y = sqrt(1LL * d * d - 1LL * x * x);
    answer += max_y / k + 1;
  }
  return answer;
}