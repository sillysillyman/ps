#include <cstdio>

int main() {
  int A, B;
  scanf("%d%d", &A, &B);
  for (int i = 0; A < 5 && B < 5; i++) i & 1 ? A += B : B += A;
  printf(A > B ? "yj" : "yt");
}