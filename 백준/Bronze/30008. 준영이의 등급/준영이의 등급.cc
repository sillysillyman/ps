#include <cstdio>

int N, K;
int arr[10] = {0, 4, 11, 23, 40, 60, 77, 89, 96, 100};

int main() {
  scanf("%d%d", &N, &K);
  for (int G, i = 0; i < K; i++) {
    scanf("%d", &G);
    int p = G * 100 / N;
    for (int d = 1; d < 10; d++) {
      if (p <= arr[d]) {
        printf("%d ", d);
        break;
      }
    }
  }
}