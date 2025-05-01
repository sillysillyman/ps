#include <cstdio>

int main() {
  int n;
  scanf("%d", &n);
  while (n--) {
    float a, b;
    scanf("%f%f", &a, &b);
    printf("The height of the triangle is %.2f units\n", 2 * a / b);
  }
}