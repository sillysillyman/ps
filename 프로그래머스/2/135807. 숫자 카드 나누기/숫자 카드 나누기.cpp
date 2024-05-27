#include <numeric>
#include <vector>

using namespace std;

int solution(vector<int> arrayA, vector<int> arrayB) {
  bool is_any_divisible;
  int answer = 0;
  int gcdA, gcdB;

  gcdA = arrayA[0];
  gcdB = arrayB[0];
  for (int num : arrayA) gcdA = gcd(gcdA, num);
  for (int num : arrayB) gcdB = gcd(gcdB, num);
  is_any_divisible = false;
  for (int num : arrayB) {
    if (!(num % gcdA)) {
      is_any_divisible = true;
      break;
    }
  }
  if (!is_any_divisible) answer = gcdA;
  is_any_divisible = false;
  for (int num : arrayA) {
    if (!(num % gcdB)) {
      is_any_divisible = true;
      break;
    }
  }
  if (!is_any_divisible) answer = max(answer, gcdB);
  return answer;
}