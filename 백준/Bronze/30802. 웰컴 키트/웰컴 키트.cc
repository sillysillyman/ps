#include <cstdio>

int main() {
  int N, T, P;
  int S, M, L, XL, XXL, XXXL;

  scanf("%d\n%d %d %d %d %d %d\n%d %d", &N, &S, &M, &L, &XL, &XXL, &XXXL, &T,
        &P);
  printf("%d\n%d %d",
         (S ? (S - 1) / T + 1 : 0) + (M ? (M - 1) / T + 1 : 0) +
             (L ? (L - 1) / T + 1 : 0) + (XL ? (XL - 1) / T + 1 : 0) +
             (XXL ? (XXL - 1) / T + 1 : 0) + (XXXL ? (XXXL - 1) / T + 1 : 0),
         N / P, N % P);
}