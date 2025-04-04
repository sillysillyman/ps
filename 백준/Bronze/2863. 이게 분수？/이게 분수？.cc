#include <algorithm>
#include <cstdio>

int main() {
  double a, b, c, d;
  scanf("%lf%lf%lf%lf", &a, &b, &c, &d);

  double arr[4] = {a / c + b / d, c / d + a / b, d / b + c / a, b / a + d / c};
  printf("%ld", std::max_element(arr, arr + 4) - arr);
}