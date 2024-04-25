#include <iostream>

using namespace std;

bool solution(int x) {
  int digit_sum = 0;
  int tmp = x;

  while (tmp) {
    digit_sum += tmp % 10;
    tmp /= 10;
  }
  return !(x % digit_sum);
}