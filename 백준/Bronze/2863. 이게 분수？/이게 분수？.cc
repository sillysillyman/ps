#include <algorithm>
#include <cstdio>

int main() {
  float a, b, c, d;
  scanf("%f%f%f%f", &a, &b, &c, &d);

  float arr[4] = {a / c + b / d, c / d + a / b, d / b + c / a, b / a + d / c};
  printf("%ld", std::max_element(arr, arr + 4) - arr);
}