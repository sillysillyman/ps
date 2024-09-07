#include <algorithm>
#include <cstdio>

using namespace std;

bool sieve[20'001];

int main() {
  fill(sieve + 2, sieve + 20'001, true);
  for (int i = 2; i < 20'001; i++) {
    if (!sieve[i]) continue;
    for (int j = 2; i * j < 20'001; j++) sieve[i * j] = false;
  }

  int N, max_factor = 0, res = 1;

  scanf("%d", &N);
  while (N--) {
    int num;

    scanf("%d", &num);
    for (int i = num; i > 0; i--) {
      if (!(num % i) && sieve[i] && i > max_factor) {
        max_factor = i;
        res = num;
        break;
      }
    }
  }
  printf("%d", res);
}