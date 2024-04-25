#include <iostream>

using namespace std;

int solution(int n) {
  if (n % 2) --n;
  return (n / 2) * (n / 2 + 1);
}