#include <cstdio>

int N;
float q, y, s;

int main() {
  scanf("%d", &N);
  while (N--) {
    scanf("%f%f", &q, &y);
    s += q * y;
  }
  printf("%.3f", s);
}