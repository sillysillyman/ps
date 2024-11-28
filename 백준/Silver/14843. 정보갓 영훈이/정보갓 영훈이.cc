#include <cstdio>

double S, R, Y;

int main() {
  int N, A, T, M, P;

  scanf("%d", &N);
  while (N--) {
    scanf("%lf%d%d%d", &S, &A, &T, &M);
    Y += (S * (1 + 1.0 / A) * (1 + (double)M / T)) / 4;
  }

  int cnt = 0;
  scanf("%d", &P);
  for (int i = 0; i < P; i++) {
    scanf("%lf", &R);
    if (Y < R) ++cnt;
  }
  if (100 * (cnt + 1) <= 15 * (P + 1))
    printf("The total score of Younghoon \"The God\" is %.2lf.", Y);
  else
    printf("The total score of Younghoon is %.2lf.", Y);
}