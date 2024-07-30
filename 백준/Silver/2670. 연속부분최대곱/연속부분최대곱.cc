#include <algorithm>
#include <cstdio>

using namespace std;

int main() {
  int N;
  double prev = 1, curr, max_product = 0;

  scanf("%d", &N);
  while (N--) {
    scanf("%lf", &curr);
    curr = max(curr, prev * curr);
    max_product = max(max_product, curr);
    prev = curr;
  }
  printf("%.3lf", max_product);
}