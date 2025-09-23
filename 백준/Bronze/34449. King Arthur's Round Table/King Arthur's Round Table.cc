#include <cstdio>

int main() {
  float d, w, n;
  scanf("%f%f%f", &d, &w, &n);
  printf(3.14159 * d >= w * n ? "YES" : "NO");
}