#include <iostream>

using namespace std;

long long solution(int a, int b) {
  if (a > b) swap(a, b);
  return (long long)(b - a + 1) * (a + b) / 2;
}