#include <cstdio>

int main() {
  int A, B, C;

  scanf("%d%d%d", &A, &B, &C);
  if (A + B + C == 0 || A + B + C == 3)
    printf("*");
  else if (A + B + C == 1) {
    if (A)
      printf("A");
    else if (B)
      printf("B");
    else
      printf("C");
  } else {
    if (!A)
      printf("A");
    else if (!B)
      printf("B");
    else
      printf("C");
  }
}