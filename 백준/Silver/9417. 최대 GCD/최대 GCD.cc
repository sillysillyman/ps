#include <cstdio>
#include <numeric>

int arr[99];

int main() {
  int N;

  scanf("%d", &N);
  while (N--) {
    char c;
    int idx = 0;

    while (scanf("%d%c", &arr[idx++], &c) && c != '\n')
      ;

    int max_gcd = 1;
    for (int i = 0; i < idx - 1; i++)
      for (int j = i + 1; j < idx; j++)
        if (int gcd = std::gcd(arr[i], arr[j]); gcd > max_gcd) max_gcd = gcd;

    printf("%d\n", max_gcd);
  }
}