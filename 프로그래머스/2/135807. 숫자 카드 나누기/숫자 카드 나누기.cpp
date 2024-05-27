#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

int solution(vector<int> arrayA, vector<int> arrayB) {
  int answer = 0;
  int gcdA, gcdB;

  sort(arrayA.begin(), arrayA.end());
  sort(arrayB.begin(), arrayB.end());
  arrayA.erase(unique(arrayA.begin(), arrayA.end()), arrayA.end());
  arrayB.erase(unique(arrayB.begin(), arrayB.end()), arrayB.end());
  gcdA = arrayA[0];
  gcdB = arrayB[0];
  for (int num : arrayA) gcdA = gcd(gcdA, num);
  for (int num : arrayB) gcdB = gcd(gcdB, num);
  for (int i = 1; i < gcdA; i++) {
    if (gcdA % i) continue;

    bool is_any_divisible = false;
    int divisor = gcdA / i;

    for (int num : arrayB) {
      if (!(num % divisor)) {
        is_any_divisible = true;
        break;
      }
    }
    if (!is_any_divisible) {
      answer = divisor;
      break;
    }
  }
  for (int i = 1; i < gcdB; i++) {
    if (gcdB % i) continue;

    bool is_any_divisible = false;
    int divisor = gcdB / i;

    for (int num : arrayA) {
      if (!(num % divisor)) {
        is_any_divisible = true;
        break;
      }
    }
    if (!is_any_divisible) {
      answer = max(answer, divisor);
      break;
    }
  }
  return answer;
}