#include <algorithm>
#include <cstdio>

using namespace std;

int W[10], K[10];

int main() {
  for (int i = 0; i < 20; i++) {
    if (i < 10)
      scanf("%d", &W[i]);
    else
      scanf("%d", &K[i - 10]);
  }
  sort(W, W + 10);
  sort(K, K + 10);
  printf("%d %d", W[7] + W[8] + W[9], K[7] + K[8] + K[9]);
}