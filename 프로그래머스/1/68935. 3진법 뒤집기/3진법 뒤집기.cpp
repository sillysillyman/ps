#include <algorithm>

using namespace std;

int solution(int n) {
  int answer = 0;
  string ternary = "";

  while (n) {
    ternary = to_string(n % 3) + ternary;
    n /= 3;
  }
  reverse(ternary.begin(), ternary.end());
  for (int mul = 1, i = ternary.length() - 1; i >= 0; i--) {
    answer += mul * (ternary[i] - '0');
    mul *= 3;
  }
  return answer;
}