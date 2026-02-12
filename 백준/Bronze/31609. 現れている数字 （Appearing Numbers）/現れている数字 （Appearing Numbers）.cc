#include <cstdio>

int N, n;
int A[10];

int main() {
  scanf("%d", &N);
  while (N--) {
    scanf("%d", &n);
    A[n]++;
  }
  for (int i = 0; i < 10; i++) if (A[i]) printf("%d\n", i);
}