#include <numeric>
#include <vector>

using namespace std;

bool is_any_divisible(vector<int>& array, int divisor) {
  for (int num : array) {
    if (num % divisor == 0) return true;
  }
  return false;
}

int solution(vector<int> arrayA, vector<int> arrayB) {
  int answer = 0;
  int gcdA, gcdB;

  gcdA = arrayA[0];
  gcdB = arrayB[0];
  for (int num : arrayA) gcdA = gcd(gcdA, num);
  for (int num : arrayB) gcdB = gcd(gcdB, num);
  if (!is_any_divisible(arrayB, gcdA)) answer = gcdA;
  if (!is_any_divisible(arrayA, gcdB)) answer = max(answer, gcdB);
  return answer;
}