#include <cstdio>

using namespace std;

int main() {
  int N, sum = 0;

  scanf("%d", &N);
  while (N--) {
    int A;

    scanf("%d", &A);
    sum += 180 * A;
  }
  printf("%d", sum - 360);
}